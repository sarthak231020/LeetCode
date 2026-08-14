class Solution {

    public void brut(int[][] matrix) 
    {
        int n = matrix.length;
        int[][] ans = new int[n][n];

        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<n;j++)
            {
                ans[j][n-1-i] = matrix[i][j];
            }
        }

        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                matrix[i][j] = ans[i][j]; 
            }
        }
    }
    
    public void optimal(int[][] matrix) 
    {
        int n = matrix.length;

        // To rotate the matrix by 90-degree clockwise.

        // Transpose
        for(int i=0;i<n;i++) 
        {
            for(int j=i+1;j<n;j++) 
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        // Reverse 
        for(int i=0;i<n;i++) 
        {
            int left = 0, right = n-1;
            while(left < right) 
            {
                int temp = matrix[i][left];
                matrix[i][left] = matrix[i][right];
                matrix[i][right] = temp;
                left++;
                right--;
            }
        }

    }

    public void rotate(int[][] matrix) {
        // brut(matrix);
        optimal(matrix);
    }
}