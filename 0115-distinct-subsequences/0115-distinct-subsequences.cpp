class Solution {
public:
    int MOD = 1e9+7;
    int solve(int ind1,int ind2,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(ind2 == 0) 
            return 1; //that we have found the entire S in text
        if(ind1 == 0) 
            return 0; //we have reached to end of the text and not able to find S.

        if(dp[ind1][ind2] != -1) 
            return dp[ind1][ind2];
        if(s1[ind1-1] == s2[ind2-1]) 
            return dp[ind1][ind2] = (solve(ind1-1,ind2-1,s1,s2,dp)%MOD + solve(ind1-1,ind2,s1,s2,dp)%MOD )%MOD;
        else
            return dp[ind1][ind2] = solve(ind1-1,ind2,s1,s2,dp)%MOD;
    }
    
    int solveTabulated(string &s1,string &s2) 
{
    int n1 = s1.size(),n2 = s2.size();
    vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
    for(int ind1=0;ind1<=n1;ind1++) 
    {
        for(int ind2=0;ind2<=n2;ind2++) 
        {
            if(ind2 == 0) 
                dp[ind1][ind2] = 1;
            else if(ind1 == 0) 
                dp[ind1][ind2] = 0;
            else
            {
                if(s1[ind1-1] == s2[ind2-1]) 
                    dp[ind1][ind2] = (dp[ind1-1][ind2-1]%MOD + dp[ind1-1][ind2]%MOD)%MOD;
                else
                    dp[ind1][ind2] = dp[ind1-1][ind2]%MOD;
            }
        }
    }
    
    return dp[n1][n2];
}

int solveTabulatedSpaceOpt(string &s1,string &s2) 
{
    int n1 = s1.size(),n2 = s2.size();
    vector<int> prev(n2+1,0),curr(n2+1,0);
    
    prev[0] = 1;
    
    for(int ind1=0;ind1<=n1;ind1++) 
    {
        for(int ind2=0;ind2<=n2;ind2++) 
        {
            if(ind2 == 0) 
                curr[ind2] = 1;
            else if(ind1 == 0) 
                curr[ind2] = 0;
            else
            {
                if(s1[ind1-1] == s2[ind2-1]) 
                    curr[ind2] = (prev[ind2-1]%MOD + prev[ind2]%MOD)%MOD;
                else
                    curr[ind2] = prev[ind2]%MOD;
            }
        }
        prev = curr;
    }
    
    return prev[n2];
}


    
    int numDistinct(string s, string t) {
        
        /* memoized code :- TC-> O(n*m) SC -> O(n*m)+O(stack Space -> O(n+m));
        int n1 = s.size(),n2=t.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        return solve(n1,n2,s,t,dp);

        */

        /*Tabulated Code :- TC -> O(n*m) SC-> O(n*m)*/
        //return solveTabulated(s,t);

        /*Space Optimized TC -> O(n*m) SC-> O(2*m)*/
        return solveTabulatedSpaceOpt(s,t);
    }
};