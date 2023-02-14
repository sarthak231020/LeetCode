class Solution {
public:
    void dfs(int i,int j,int srcColor,int color,vector<vector<int>>& visited,vector<vector<int>>& image) 
    {
        visited[i][j] = color;
        
        if(i-1 >=0 && image[i-1][j] == srcColor && visited[i-1][j] != color)
            dfs(i-1,j,srcColor,color,visited,image);
        if(j-1 >= 0 && image[i][j-1] == srcColor && visited[i][j-1]!= color)
            dfs(i,j-1,srcColor,color,visited,image); 
        if(i+1 < image.size() && image[i+1][j] == srcColor && visited[i+1][j]!= color) 
            dfs(i+1,j,srcColor,color,visited,image); 
        if(j+1 < image[0].size() && image[i][j+1] == srcColor && visited[i][j+1]!= color) 
            dfs(i,j+1,srcColor,color,visited,image);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int N = image.size();
        int M = image[0].size();
        vector<vector<int>> visited(N,vector<int> (M,-1));
        dfs(sr,sc,image[sr][sc],color,visited,image);
        
        for(int i=0;i<N;i++) 
        {
            for(int j=0;j<M;j++) 
            {
                if(visited[i][j] != color) 
                {
                    visited[i][j] = image[i][j];
                }
            }
        }
        
        return visited;
    }
};