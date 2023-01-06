class Solution {
public:
    int solve(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp)
    {
        if(j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size()) 
            return -1e8;
        if(i == grid.size()-1) 
        {
            if(j1 == j2)  // They reached the same cell 
                return grid[i][j1];
            else 
            {
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        if(dp[i][j1][j2] != -1) 
            return dp[i][j1][j2];
        
        int maxi = 0;
        for(int dj1 = j1-1;dj1 <= j1+1; dj1++) 
        {
            for(int dj2 = j2-1;dj2 <= j2+1; dj2++) 
            {
                int rs = solve(i+1,dj1,dj2,grid,dp);
                if(j1 == j2)
                {
                    if(rs != -1e8)
                    {
                        maxi = max(maxi,grid[i][j1]+rs);
                    }
                }
                else 
                {
                    if(rs != -1e8)
                    {
                        maxi = max(maxi,grid[i][j1] + grid[i][j2] + rs);
                    }
                }
            }
        }
        
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (m+1,vector<int> (m+1,-1)));
        return solve(0,0,m-1,grid,dp);
    }
};