class Solution {
    public boolean better(int[][] matrix,int target) 
    {
        // The idea here is to check in each row using binary search.
        // TC -> O(rows * log(cols)).
        for(int i=0;i<matrix.length;i++) 
        {
            int low = 0, high = matrix[i].length;
            while(low <= high) 
            {
                int mid = low + (high - low)/2;
                if(matrix[i][mid] == target)
                    return true;
                if(matrix[i][mid] > target) 
                    high = mid-1;
                else
                    low = mid+1;
            }
        }
        return false;
    }

    public boolean optimal(int[][] matrix,int target)
    {
        // if we carefully observe --> while standing at top right or bottom left
        // we can eliminate the row or col on basis of target since it is combinely sorted merging them gives a sorted array.
        int rows = matrix.length;
        int cols = matrix[0].length;
        int row = 0, col = cols-1; // standing at top right.
        while(row < rows && col >= 0)
        {
            if(matrix[row][col] == target)
                return true;
            if(matrix[row][col] > target)
                col--; // everything below this are greater so move col 
            else
                row++; // everything in this row in left side are always lesser so move row.
        }
        return false;
    }
    
    public boolean searchMatrix(int[][] matrix, int target) {
        // return better(matrix,target);
        
        return optimal(matrix,target);
    }
}