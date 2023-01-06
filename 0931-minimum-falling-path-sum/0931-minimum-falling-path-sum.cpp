class Solution {
public:
    
    int solve(int i,int j,vector<vector<int>>& matrix,vector<vector<int>> &dp)
    {
        if(i == 0) 
            return matrix[i][j];
        
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        int up = matrix[i][j] + solve(i-1,j,matrix,dp); 
        
        int upleft = INT_MAX; 
        if(j-1 >= 0)
        {
            upleft = matrix[i][j] + solve(i-1,j-1,matrix,dp); 
        }
        int upright = INT_MAX;
        if(j + 1 < matrix.size()) 
            upright = matrix[i][j] + solve(i-1,j+1,matrix,dp); 
        
        return dp[i][j] =  min(up,min(upleft,upright)); 
    }
    
    int solveTabulated(vector<vector<int>>& matrix,vector<vector<int>> &dp)
    {
        int n = matrix.size();
        
        
        //Converting the base case.
        for(int j=0;j<n;j++) 
        {
            dp[0][j] = matrix[0][j];
        }
        
        for(int i=1;i<n;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                int up = matrix[i][j] + dp[i-1][j]; 

                int upleft = INT_MAX; 
                if(j-1 >= 0)
                {
                    upleft = matrix[i][j] + dp[i-1][j-1]; 
                }
                int upright = INT_MAX;
                if(j + 1 < matrix.size()) 
                    upright = matrix[i][j] + dp[i-1][j+1]; 

                dp[i][j] =  min(up,min(upleft,upright)); 
            }
        }
        
        int ans = INT_MAX; 
        
        for(int j=0;j<n;j++) 
        {
            ans = min(ans,dp[n-1][j]);
        }
        
        return ans;
        
    }
    
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Recursive Memoized Code 
        int n = matrix.size();
        // int ans = INT_MAX;
        // for(int i=0;i<n;i++) 
        // {
        //     vector<vector<int>> dp(n+1,vector<int> (n+1,-1)); 
        //     ans = min(ans,solve(n-1,i,matrix,dp));
        // }
        // return ans;
        
        // Tabulated Code 
        vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        return solveTabulated(matrix,dp);
        
    }
};