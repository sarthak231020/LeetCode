//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        
        int N = grid.size();
        int M = grid[0].size();
        int freshOranges = 0; // Taking the count of the oranges so that we can check whether all oranges got rotten at the end in O(1).
        vector<vector<int>> visited(N,vector<int> (M)); // So that we will not change the original 
        // It is a good practice to keep the Original data unchanged at the end of the program.
        visited = grid;
        queue<pair<pair<int,int>,int>> q; // we will store like (x,y) and time it have taken to get rotten.
        
        for(int i=0;i<N;i++) 
        {
            for(int j=0;j<M;j++) 
            {
                if(grid[i][j] == 1) 
                {
                    freshOranges++;
                }
                else if(grid[i][j] == 2) 
                {
                    visited[i][j] = 2;
                    q.push({{i,j},0}); //Initially Push all the rotten oranges.
                }
            }
        }
        // we try with UP,RIGHT,DOWN,LEFT
        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,1,0,-1};
        int Time = 0;
        // Using the BFS technique
        while(!q.empty())
        {
            pair<pair<int,int>,int> ele = q.front();
            q.pop();
            for(int i=0;i<4;i++) 
            {
                
                int x = ele.first.first;
                int y = ele.first.second;
                int curTime = ele.second;
                Time = max(Time,ele.second);
                int negX = x+dx[i]; // calculating the neighbour index.
                int negY = y+dy[i]; // calculating the neighbour index.
                
                if(negX >= 0 && negX < N && negY >= 0 && negY < M && visited[negX][negY] == 1)
                {
                    q.push({{negX,negY},curTime+1});
                    freshOranges--;
                    visited[negX][negY] = 2; // now marking it as rotten.
                }
            }
        }
        
        if(freshOranges == 0) // we are successfully rotten all the oranges.
            return Time;
        return -1;
        
        
        
        
        // Code here
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends