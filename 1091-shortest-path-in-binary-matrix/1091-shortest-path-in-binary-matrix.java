class Solution {

    public int shortestPathBinaryMatrix(int[][] grid) {

        int m = grid.length;
        int n = grid[0].length; 
        boolean[][] visited = new boolean[m][n];
        
        
        if(grid[0][0] == 1) 
            return -1;
        if(m == 1 && n==1) 
            return 1;

        Deque<int[]> queue = new ArrayDeque<>();
        queue.offer(new int[]{0,0,1});
        visited[0][0] = true;
        while(!queue.isEmpty()) 
        {
            int r = queue.peek()[0];
            int c = queue.peek()[1];
            int dist = queue.peek()[2];
            queue.remove();

            for(int x=-1;x<=1;x++) 
            {
                for(int y=-1;y<=1;y++) 
                {
                    if(x == 0 && y == 0) 
                        continue;
                    int currRow = r + x;
                    int currCol = c + y;
                    if(currRow >= 0 && currRow < m && currCol >= 0 && currCol < n && grid[currRow][currCol] == 0 && !visited[currRow][currCol]) 
                    {
                        visited[currRow][currCol] = true;
                        if(currRow == m-1 && currCol == n-1) 
                            return dist+1;
                        queue.offer(new int[]{currRow,currCol,dist+1});
                    }
                }
            }
        }
        return -1;
    }
}