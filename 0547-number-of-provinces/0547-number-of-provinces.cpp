class Solution {
public:
    
    void dfs(int node,vector<int> &visited,vector<vector<int>>& isConnected)
    {
        visited[node] = 1; 
        
        for(int j=0;j<isConnected[node].size();j++) 
        {
            if(isConnected[node][j] == 1 && visited[j] == 0) 
            {
                dfs(j,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size(); // Number of nodes present.
        vector<int> visited(N+1,0); //Initializing the visited array as 0.
        
        int components = 0;
        for(int i=0;i<N;i++) 
        {
            if(visited[i] == 0) 
            {
                components++;
                dfs(i,visited,isConnected);
            }
        }
        
        return components;
        
    }
};