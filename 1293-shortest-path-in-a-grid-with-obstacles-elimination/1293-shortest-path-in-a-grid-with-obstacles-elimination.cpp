class Solution {
public:
    
//     int solve(int i,int j,int R,int C,int B,vector<vector<int>>& grid,vector<vector<vector<int>>> dp,vector<vector<int>> visited)
//     {
//         // cout<<"RUNNING"<<endl;
//         if(i == R-1 && j == C-1)
//             return 0;
//         if(dp[i][j][B] != -1) 
//             return dp[i][j][B];
//         //             //   
//         vector<int> x = {-1,0,1,0};
//         vector<int> y = {0,1,0,-1};
//         int mini = 5000;
//         visited[i][j] = 1;
//         for(int k=0;k<4;k++) 
//         {
//             if((i+x[k] != -1) && (j+y[k] != -1) && (i+x[k] != R) && (j+y[k] != C) && visited[i+x[k]][j+y[k]] == 0)
//             {
//                 if(grid[i+x[k]][j+y[k]] == 1)
//                 {
//                     if(B >= 1) 
//                     {
//                         mini = min(mini,1+solve(i+x[k],j+y[k],R,C,B-1,grid,dp,visited));
//                     }
//                 }
//                 else
//                 {
//                     mini = min(mini,1+solve(i+x[k],j+y[k],R,C,B,grid,dp,visited));
//                 }
//             }
//         }
//         return dp[i][j][B] = mini; 
//         // return mini;
//     }
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        int R = grid.size(); 
        int C = grid[0].size();
        // cout<<R<<" "<<C<<endl;
        
//         vector<vector<vector<int>>> dp(R+1,vector<vector<int>>(C+1,vector<int> (k+1,-1)));
        
//         vector<vector<int>> visited(R+1,vector<int>(C+1,0)); 
//         int ans = solve(0,0,R,C,k,grid,dp,visited);
//         if(ans >= 5000) 
//             return -1;
//         return ans;
        
        
        vector<vector<int>> visited(R+1,vector<int> (C+1,-1));
        queue<vector<int>> q;
        q.push({0,0,0,k}); //queue is storing the current state we are at 0,0 steps -> 0 and have k obstacles.
        int ans = INT_MAX;
        while(!q.empty()) 
        {
            auto t = q.front();
            int x = t[0];
            int y = t[1];
            int steps = t[2];
            int obstacles = t[3];
            q.pop();
            if(x == -1 || y == -1 || x == R || y == C) 
                continue;
            if(x == R-1 && y == C-1) 
                return steps;
            if(grid[x][y] == 1) 
            {
                if(obstacles >= 1) 
                    obstacles--;
                else
                    continue;
            }
            if(visited[x][y] != -1 && visited[x][y] >= obstacles) 
            {
                continue;
            }
            visited[x][y] = obstacles;
            q.push({x,y-1,steps+1,obstacles});
            q.push({x,y+1,steps+1,obstacles});
            q.push({x-1,y,steps+1,obstacles});
            q.push({x+1,y,steps+1,obstacles});
        }
        
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};