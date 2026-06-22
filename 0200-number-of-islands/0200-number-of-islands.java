class Solution {

    public void dfs(int row,int col,char[][] grid,boolean[][] visited)
    {
        if(row < 0 || col < 0 || row >= grid.length || col >= grid[0].length || visited[row][col] || grid[row][col] == '0')
        { 
            return;
        }
        visited[row][col] = true; 
        dfs(row-1,col,grid,visited);
        dfs(row,col+1,grid,visited);
        dfs(row+1,col,grid,visited);
        dfs(row,col-1,grid,visited);
    }

    public int numIslands(char[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        boolean[][] visited = new boolean[rows][cols];
        int cnt = 0;
        for(int i=0;i<rows;i++) 
        {
            for(int j=0;j<cols;j++) 
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    dfs(i,j,grid,visited);
                    cnt++;
                }
            }
        }

        return cnt;
    }
}