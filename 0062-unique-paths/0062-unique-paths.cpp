class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>> &dp) 
    {
        if(i < 0 || j < 0) 
            return 0;
        if(i == 0 && j == 0) 
            return 1;
        if(dp[i][j] != -1) 
            return dp[i][j]; 
        
        return dp[i][j] = (solve(i-1,j,dp) + solve(i,j-1,dp));
        
    }
    
    int solveTabulated(int m,int n) 
    {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        
        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                if(i == 0 && j == 0) 
                    dp[i][j] = 1;
                else
                {
                    int up = 0;
                    if(i > 0)
                        up =dp[i-1][j];
                    int left = 0; 
                    if(j > 0) 
                        left = dp[i][j-1];
                    
                    dp[i][j] = (up+left);
                }
            }
        }
        return dp[m-1][n-1];
    }
    
    
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m,vector<int> (n,-1));
        // return solve(m-1,n-1,dp);
        
        return solveTabulated(m,n);
        
    }
};