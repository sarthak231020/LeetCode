class Solution {
    
    public boolean betterSol(int[][] matrix,int target) 
    {

        // The idea here is simple to write the code firstly to find out the
        // 1. find the target row.
        // 2. find the target col.
        int ROWS = matrix.length, COLS = matrix[0].length;
        // (0,0) --> (0+0)/2; --> 0

        // Running Binary Search on row.
        int top = 0, bot = ROWS-1, rowNum = 0;

        while(top <= bot) 
        {
            int row = top + (bot-top)/2; // In order to avoid integer overflow.

            // Here we will check if that rows first val is lesser than 
            if(matrix[row][0] > target)
                bot = row-1;
            else if(matrix[row][COLS-1] < target)
                top = row+1;
            else 
            {
                rowNum = row;
                break;
            }
        }

        // in case we are not able to find any row there then.
        if(top > bot) 
            return false;

        int r = 0, c = COLS-1;
    
        while(r <= c) 
        {
            int m = r + (c - r)/2;
            if(matrix[rowNum][m] > target) 
                c = m-1;
            else if(matrix[rowNum][m] < target) 
                r = m+1;
            else 
                return true;
        }
        
        return false;
    }

    public boolean optimalSol(int[][] matrix,int target)
    {
        int ROWS = matrix.length, COLS = matrix[0].length;
        int left = 0, right = ROWS*COLS-1;
        // The idea is simple since every row is sorted and next element is greater than previous greater 
        // let's say matrix 4*4 --> 
        // left = 0, right = 15 --> mid --> (left  + right)/2 --> (0 + 15)/2 --> 7
        // row --> 7/3 --> 2 col --> 7%3 --> 1 

        while(left <= right)
        {
            int mid = left + (right-left)/2;
            int row = mid/COLS, col = mid%COLS;

            if(matrix[row][col] > target)
            {
                right = mid-1;
            }
            else if(matrix[row][col] < target)
            {
                left = mid+1;
            }
            else
            {
                return true;
            }
        }

        return false;
        
    }

    public boolean searchMatrix(int[][] matrix, int target) {
        // return betterSol(matrix,target);
        return optimalSol(matrix,target);
    }
}