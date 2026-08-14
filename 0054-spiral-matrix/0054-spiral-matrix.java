class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int rows = matrix.length; 
        int cols = matrix[0].length;
        int left = 0, right = cols, top = 0, bottom = rows;
        List<Integer> ans = new ArrayList<>();
        while(top < bottom && left < right) 
        {
            for(int i=left;i<right;i++) 
                ans.add(matrix[top][i]);
            top++;
            for(int i=top;i<bottom;i++) 
                ans.add(matrix[i][right-1]);
            right--;

            // Edge case if we have only one row or one col
            if(top >= bottom || left >= right)
                break;
    
            for(int i=right-1;i>=left;i--)
                ans.add(matrix[bottom-1][i]);
            bottom--;
            for(int i=bottom-1;i>=top;i--) 
                ans.add(matrix[i][left]);
            left++;
        }
        return ans;
    }
}