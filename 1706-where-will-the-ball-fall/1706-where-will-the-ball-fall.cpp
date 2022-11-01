class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q; //Ball No, Current Position of Ball (x,y).
        int M = grid.size(); 
        int N = grid[0].size();
        
        for(int i=0;i<N;i++) 
        {
            q.push({i,{0,i}});
        }
        
        vector<int> ans(N,-1);
        while(!q.empty()) 
        {
            auto t = q.front();
            q.pop();
            int B = t.first;
            int x = t.second.first;
            int y = t.second.second;
            
            if(x == M)
            {
                ans[B] = y; //Ball no B gets out of yth column.
            }
            else 
            {
                int J = grid[x][y]+y; //in case -1 check for prev position if prev == +1 (grid[x][y] != grid[x]                                       //[J]) there will be coliision since \/ formed. else no collision both / / 
                                      //Similarly in case +1 check for next position if next val = -1 collision 
                                      //else No Collision \ \ both are going rightwards.
                
                if((J>=0 && J<N) && (grid[x][y] == grid[x][J])) 
                    q.push({B,{x+1,J}});
            }   
        }
        return ans;
    }
};