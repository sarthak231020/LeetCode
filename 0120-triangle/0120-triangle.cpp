class Solution {
public:
    int solve(int i,int j,vector<vector<int>> &triangle,vector<vector<int>> &dp) 
    {
        if(i == triangle.size())
            return 0; 
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        
        return dp[i][j] = triangle[i][j] + min(solve(i+1,j,triangle,dp),solve(i+1,j+1,triangle,dp)); 
    }
    
    int solveTabulated(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,0)); 
        //No need to write base case since we already filled the dp with zeros.
        
        for(int i=n-1;i>=0;i--) 
        {
            for(int j=i;j>=0;j--) 
            {
                dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        // int n = triangle.size(); 
        // vector<vector<int>> dp(n,vector<int> (n,-1)); 
        // return solve(0,0,triangle,dp);
        
        return solveTabulated(triangle);
    }
};