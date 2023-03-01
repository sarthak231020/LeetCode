class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int N = grid.size();
        int M = grid[0].size();
        
        int flag = true;
        for(int i=0;i<grid.size();i++) 
        {
            for(int j=0;j<grid[0].size();j++) 
            {
                if(grid[i][j] == 2) 
                {
                    q.push({i,j});
                }
                if(grid[i][j] == 1) 
                {
                    flag = false;
                }
            }
        }
        if(flag == true) 
        {
            return 0;
        }
        
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        
        int min = -1;
        while(!q.empty()) 
        {
            int size = q.size();
            for(int i=0;i<size;i++) 
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i=0;i<4;i++) 
                {
                    int negX = x+dx[i];
                    int negY = y+dy[i];
                    if(negX >= 0 && negX < N && negY >= 0 && negY < M && grid[negX][negY] == 1)
                    {
                        grid[negX][negY] = 2; // mark it as rotten.
                        q.push({negX,negY}); // push it so its neighbours can rotten 
                    }
                }
                
            }
            min++;
        }
        for(int i=0;i<N;i++) 
        {
            for(int j=0;j<M;j++) 
            {
                if(grid[i][j] == 1) 
                    return -1;
            }
        }
        return min;
    }
};