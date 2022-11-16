#include <bits/stdc++.h> 
int solve(int ind,int w,vector<int> &profit, vector<int> &weight,vector<vector<int>> &dp)
{
    if(ind == 0) 
    {
        if(weight[ind] <= w)
            return ((w/weight[ind])*profit[ind]); 
        else 
            return 0;
    }
    if(dp[ind][w] != -1) 
        return dp[ind][w];
    int pick = INT_MIN;
    if(weight[ind] <= w) 
    {   //we earned that profit since we are allowed to take it multiple times so 
        //include profit and pass same index.
        pick = profit[ind]+solve(ind,w-weight[ind],profit,weight,dp);
    }
    
    int notPick = solve(ind-1,w,profit,weight,dp);
    
    return dp[ind][w] = max(pick,notPick);
}

int solveTabulated(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n,vector<int> (w+1,0));
    
    for(int j = 0; j <= w; j++) 
    {
        if(weight[0] <= j) 
        {
            dp[0][j] = ((j/weight[0])*profit[0]);
        }
        else 
        {
            dp[0][j] = 0;
        }
    }
    for(int i=0;i<n;i++) 
    {
        dp[i][0] = 0; // we can't achieve any profit in case of w = 0 
    }
    
    
    for(int ind=1;ind<n;ind++) 
    {
        for(int j=1;j<=w;j++) 
        {
            int pick = INT_MIN;
            if(weight[ind] <= j) 
            {   //we earned that profit since we are allowed to take it multiple times so 
                //include profit and pass same index.
                pick = profit[ind]+dp[ind][j-weight[ind]];
            }

            int notPick = dp[ind-1][j];

            dp[ind][j] = max(pick,notPick);
        }
    }
//     for(auto i:dp) 
//     {
//         for(auto j:i) 
//             cout<<j<<" ";
//         cout<<endl;
//     }
    return dp[n-1][w];
}

int solveTabulatedSpaceOpt(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w+1,0),curr(w+1,0);
    
    for(int j = 0; j <= w; j++) 
    {
        if(weight[0] <= j) 
        {
            prev[j] = ((j/weight[0])*profit[0]);
        }
        else 
        {
            prev[j] = 0;
        }
    }
    prev[0] = 0; //capacity 0 then no profit.
    
    
    for(int ind=1;ind<n;ind++) 
    {
        curr[0] = 0; //capacity 0 then no profit.
        for(int j=1;j<=w;j++) 
        {
            int pick = INT_MIN;
            if(weight[ind] <= j) 
            {   //we earned that profit since we are allowed to take it multiple times so 
                //include profit and pass same index.
                pick = profit[ind]+curr[j-weight[ind]];
            }

            int notPick = prev[j];

            curr[j] = max(pick,notPick);
        }
        prev = curr;
    }
//     for(auto i:dp) 
//     {
//         for(auto j:i) 
//             cout<<j<<" ";
//         cout<<endl;
//     }
    return prev[w];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
//     vector<vector<int>> dp(n,vector<int> (w+1,-1));
//     memoized :- TC -> O(n*w) SC -> O(n*w) + O(stack space -> N). 
//     return solve(n-1,w,profit,weight,dp);
//     Tabulated :- TC -> O(n*w) SC -> O(n*w)
//     return solveTabulated(n,w,profit,weight);
    //     Tabulated Space Optimized:- TC -> O(n*w) SC -> O(2*w)
    return solveTabulatedSpaceOpt(n,w,profit,weight);
}
