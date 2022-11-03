int solve(int i,int j,int n,int m,vector< vector< int> > &mat,vector<vector<int>> &dp)
{
    if(i == -1 || j == -1 || mat[i][j] == -1) 
        return 0;
    if(i == 0 && j==0) 
        return 1;
    if(dp[i][j] != -1) 
        return dp[i][j];
    int MOD = 1000000007;
    int left = solve(i,j-1,n,m,mat,dp)%(MOD);
    int up = solve(i-1,j,n,m,mat,dp)%MOD;
    
    return dp[i][j] = (left+up)%MOD;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    /* for memoized CODE TC -> O(N*M) (at max there will m*n calls) SC -> O(n-1+m-1)+O(DP(N*M)).
    vector<vector<int>> dp(n,vector<int> (m,-1));
    return solve(n-1,m-1,n,m,mat,dp);
    */
    
    /* Tabulation Way -> TC SAME SC-> O(n*m).
    vector<vector<int>> dp(n,vector<int> (m,0));
    int MOD = 1000000007;
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<m;j++) 
        {
            if(i == 0 && j == 0) 
                dp[i][j] = 1;
            else 
            {
                int up = 0,left = 0; 
                if(mat[i][j] == -1) 
                    dp[i][j] = 0; 
                else
                {
                    if(j > 0)
                        left = dp[i][j-1]%MOD;
                    if(i > 0)
                        up = dp[i-1][j]%MOD;
                    dp[i][j] = (left+up)%MOD;
                }
            }
        }
    }
    
    return dp[n-1][m-1];
   
   */
    //SPACE OPTIMIZED TC-> SAME SC-> O(2*M) 
    vector<int> prev(m,0);
    int MOD = 1000000007;
    for(int i=0;i<n;i++) 
    {
        vector<int> curr(m,0);
        for(int j=0;j<m;j++) 
        {
            if(i == 0 && j == 0) 
                curr[j] = 1;
            else 
            {
                int up = 0,left = 0; 
                if(mat[i][j] == -1) 
                    curr[j] = 0; 
                else
                {
                    if(j > 0)
                        left = curr[j-1]%MOD;
                    if(i > 0)
                        up = prev[j]%MOD;
                    curr[j] = (left+up)%MOD;
                }
            }
        }
        prev = curr;
    }
    
    return prev[m-1];
    // Write your code here
}
