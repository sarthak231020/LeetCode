class Solution {


    public boolean searchMatrix(int[][] matrix, int target) {
        // Given already that last element of a row is always lesser than next ka first element.So we can consider it as single sorted list 
        // 1 --> total length-1 
        // then row = i/cols
        // col = i%cols
        int rows = matrix.length;
        int cols = matrix[0].length;
        int low = 0, high = rows*cols-1;

        while(low <= high) 
        {
            int mid = low + (high - low)/2;
            int row = mid/cols;
            int col = mid%cols;
            if(matrix[row][col] == target) 
                return true;
            else if(matrix[row][col] > target)
                high = mid-1;
            else
                low = mid+1;
        }

        return false;
    }
}