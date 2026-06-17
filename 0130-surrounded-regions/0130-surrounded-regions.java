class Solution {

    public void usingDfs(int r,int c,int rows,int cols,char[][] board,boolean[][] visited)
    {
        if(r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != 'O' || visited[r][c])
            return;
        visited[r][c] = true;
        usingDfs(r-1,c,rows,cols,board,visited);
        usingDfs(r,c+1,rows,cols,board,visited);
        usingDfs(r+1,c,rows,cols,board,visited);
        usingDfs(r,c-1,rows,cols,board,visited);
    }


    public void solve(char[][] board) {

        int rows = board.length;
        int cols = board[0].length;
        boolean[][] visited = new boolean[rows][cols];

        for(int i=0;i<rows;i++) 
        {
            for(int j=0;j<cols;j++) 
            {
                if((i == 0 || i == rows-1 || j == 0 || j == cols-1) && (board[i][j] == 'O')) 
                {
                    usingDfs(i,j,rows,cols,board,visited);
                }
            }
        }
        // Using BFS 
        // Deque<int[]> queue = new ArrayDeque<>();

        // for(int i=0;i<rows;i++) 
        // {
        //     for(int j=0;j<cols;j++) 
        //     {
        //         if((i == 0 || i == rows-1 || j == 0 || j == cols-1) && (board[i][j] == 'O'))
        //             queue.offer(new int[]{i,j});
        //     }
        // }

        // int[] dirX = {-1,0,1,0};
        // int[] dirY = {0,1,0,-1};

        // while(!queue.isEmpty()) 
        // {
        //     int row = queue.peek()[0];
        //     int col = queue.peek()[1];
        //     queue.remove();

        //     for(int i=0;i<4;i++) 
        //     {
        //         int currRow = row + dirX[i];
        //         int currCol = col + dirY[i];

        //         if(currRow < 0 || currRow >= rows || currCol < 0 || currCol >= cols || board[currRow][currCol] != 'O')
        //             continue;
        //         board[currRow][currCol] = 'C';
        //         queue.offer(new int[]{currRow,currCol});
        //     }
        // }
        


        for(int i=0;i<rows;i++) 
        {
            for(int j=0;j<cols;j++) 
            {
                if(!visited[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }

    }
}