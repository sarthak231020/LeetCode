class Solution {

    public int dfs(int row,int col,int[][] heights,boolean[][] visited,int diff) 
    {
        if(row == heights.length-1 && col == heights[0].length-1) 
            return diff;
        if(row < 0 || col < 0 || row >= heights.length || col >= heights[0].length || visited[row][col])
            return (int)(1e9);
        visited[row][col] = true;
        int ans = (int)(1e9);
        if(row-1 >= 0)
        {
            ans = Math.min(ans,dfs(row-1,col,heights,visited,Math.max(diff,Math.abs(heights[row][col] - heights[row-1][col]))));
        }
        if(diff > ans) 
            return (int)(1e9);
        if(col+1 < heights[0].length)
        {
            ans = Math.min(ans,dfs(row,col+1,heights,visited,Math.max(diff,Math.abs(heights[row][col] - heights[row][col+1]))));
        }
        if(diff > ans) 
            return (int)(1e9);
        if(row+1 < heights.length)
        {
            ans = Math.min(ans,dfs(row+1,col,heights,visited,Math.max(diff,Math.abs(heights[row][col] - heights[row+1][col]))));
        }
        if(diff > ans) 
            return (int)(1e9);
        if(col-1 >= 0)
        {
            ans = Math.min(ans,dfs(row,col-1,heights,visited,Math.max(diff,Math.abs(heights[row][col] - heights[row][col-1]))));
        }
        if(diff > ans) 
            return (int)(1e9);
        visited[row][col] = false;
        return ans;
    }

    public int minimumEffortPath(int[][] heights) {
        int m = heights.length;
        int n = heights[0].length;

        int[][] dist = new int[m][n];

        for(int[] row : dist) 
            Arrays.fill(row,Integer.MAX_VALUE);

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.add(new int[]{0,0,0});
        int[] dirX = {-1,0,1,0};
        int[] dirY = {0,1,0,-1};

        while(!pq.isEmpty()) 
        {
            int[] current = pq.poll();
            int diff = current[0];
            int x = current[1];
            int y = current[2];
            if(x == m-1 && y == n-1) 
                return diff;

            for(int i=0;i<4;i++) 
            {
                int currRow = x + dirX[i];
                int currCol = y + dirY[i];
                if(currRow >= 0 && currRow < m && currCol >= 0 && currCol < n)
                {
                    int newDiff = Math.max(Math.abs(heights[x][y]-heights[currRow][currCol]),diff);
                    
                    if(newDiff < dist[currRow][currCol])
                    {
                        dist[currRow][currCol] = newDiff;
                        pq.offer(new int[]{newDiff,currRow,currCol});
                    }
                }
            }
        }
        return 0;
    }
}