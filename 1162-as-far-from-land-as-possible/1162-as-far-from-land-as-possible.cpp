class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        vector<pair<int,int>> ones;
        for(int i=0;i<grid.size();i++) 
        {
            for(int j=0;j<grid[0].size();j++) 
            {
                if(grid[i][j] == 1) 
                {
                    ones.push_back({i,j});
                }
            }
        }
        
        int ans = -1;
        for(int i=0;i<grid.size();i++) 
        {
            for(int j=0;j<grid[0].size();j++) 
            {
                if(grid[i][j] == 0) 
                {
                    int mindist = INT_MAX;
                    for(auto k:ones) 
                    {
                        int dist = abs(k.first-i) + abs(k.second-j);
                        mindist = min(mindist,dist);
                    }
                    if(mindist != INT_MAX)
                        ans = max(ans,mindist);
                }
            }
        }
        
        return ans;
        
        
    }
};