//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    void dfs(int i,int j,vector<vector<int>> &visited,vector<vector<char>>& grid)
    {
        
        visited[i][j] = 1;
        
        for(int dx = -1;dx<=1;dx++) 
        {
            for(int dy = -1;dy<=1;dy++) 
            {
                if(((i+dx >= 0) && (i+dx < grid.size()) && (j+dy >= 0) && (j+dy < grid[0].size())) && (grid[i+dx][j+dy] == '1') && (visited[i+dx][j+dy] == 0))
                {
                    dfs(i+dx,j+dy,visited,grid);
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int N = grid.size(); 
        int M = grid[0].size();
        vector<vector<int>> visited(N+1,vector<int> (M+1,0));
        int islands = 0;
        for(int i=0;i<N;i++) 
        {
            for(int j=0;j<M;j++) 
            {
                if(grid[i][j] == '1' && visited[i][j] == 0) 
                {
                    islands++;
                    dfs(i,j,visited,grid);
                }
            }
        }
        
        return islands;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends