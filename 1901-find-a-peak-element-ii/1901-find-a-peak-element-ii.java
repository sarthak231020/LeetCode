class Solution {

    public int getMaxEleInd(int[][] mat,int col)
    {
        int maxInd = 0,maxEle = mat[0][col];
        for(int row=0;row<mat.length;row++)
        {
            if(mat[row][col] > maxEle)
            {
                maxEle = mat[row][col];
                maxInd = row;
            }
        }

        return maxInd;
    }

    public int[] findPeakGrid(int[][] mat) {
        int rows = mat.length;
        int cols = mat[0].length;

        int low = 0, high = cols-1;

        while(low <= high) 
        {
            int mid = low + (high - low)/2;
            int maxInd = getMaxEleInd(mat,mid);

            int left = mid-1 >= 0 ? mat[maxInd][mid-1] : -1;
            int right = mid+1 < cols ? mat[maxInd][mid+1] : -1;

            if(mat[maxInd][mid] > left && mat[maxInd][mid] > right)
                return new int[]{maxInd,mid};
            if(mat[maxInd][mid] < left)
                high = mid-1;
            else
                low = mid+1;
        }

        return new int[]{-1,-1};
    }
}