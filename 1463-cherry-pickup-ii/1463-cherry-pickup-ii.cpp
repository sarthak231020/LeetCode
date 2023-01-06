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
    
    int solveTabulated(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size(); 
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (m,0)));
        
        for(int j1=0;j1<m;j1++) 
        {
            for(int j2 = 0;j2<m; j2++) 
            {
                if(j1 == j2)  // They reached the same cell 
                    dp[n-1][j1][j2] = grid[n-1][j1];
                else 
                {
                    dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
                }
            }
        }
        
        for(int i=n-2;i>=0;i--) 
        {
            for(int j1=0;j1<m;j1++) 
            {
                for(int j2 = 0;j2 < m ; j2++) 
                {
                    int maxi = 0;
                    for(int dj1 = j1-1;dj1 <= j1+1; dj1++) 
                    {
                        for(int dj2 = j2-1;dj2 <= j2+1; dj2++) 
                        {
                            int rs = -1e8;
                            if(dj1 >= 0 && dj1 < m && dj2 >= 0 && dj2 < m) 
                                rs = dp[i+1][dj1][dj2];
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
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }    
    
    int cherryPickup(vector<vector<int>>& grid) {
        // int n = grid.size(); 
        // int m = grid[0].size();
        // vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (m+1,vector<int> (m+1,-1)));
        // return solve(0,0,m-1,grid,dp);
        
        return solveTabulated(grid);
    }
};