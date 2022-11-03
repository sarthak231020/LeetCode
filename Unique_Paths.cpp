#include <bits/stdc++.h> 

int solve(int i,int j,int m,int n,vector<vector<int>> &dp) 
{
    if(i == -1 || j == -1) 
        return 0;
    if(i == 0 && j == 0) 
        return 1;
    if(dp[i][j] != -1) 
        return dp[i][j];
    int left = solve(i,j-1,m,n,dp);
    int up = solve(i-1,j,m,n,dp);
    
    return dp[i][j] = left+up;
}

int uniquePaths(int m, int n) {
      /*  FOR MEMOIZED CODE
       TC-> O(M*N) SC -> O((m-1)+(n-1))+O(DP(M*N)).
//     vector<vector<int>> dp(m,vector<int> (n,-1));
//     return solve(m-1,n-1,m,n,dp); //Memoized Solution.
    
     */
    
    /* FOR TABULATION WAY :- TC-> O(M*N) SC -> O(DP->(M*N)).
//     vector<vector<int>> dp(m+1,vector<int> (n+1,0));
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == 0 && j == 0) //The Base Case.
                dp[i][j] = 1; 
            else 
            {
                int up = 0,left = 0; 
                if(i > 0) 
                    up = dp[i-1][j];
                if(j > 0) 
                    left = dp[i][j-1];
                dp[i][j] = up+left;
            }
        }
    }
    
    return dp[m-1][n-1];
    
    */
    
    //SPACE OPTIMIZED WAY :- PRECISELY WE NEED previous row & curr row. TC remain same but SC -> O(2*n);
    vector<int> prev(n,0);
    prev[0] = 1;
    
    for(int i=0;i<m;i++) 
    {
        vector<int> curr(n,0);
        for(int j=0;j<n;j++) 
        {
            if(j == 0) 
                curr[j] = 1;
            else
            {
                int up = 0,left = 0;
                if(i > 0) 
                    up = prev[j];
                if(j > 0) 
                    left = curr[j-1];
                curr[j] = up+left;
            }
        }
        prev = curr;
    }
    
    return prev[n-1];
	// Write your code here.
}
