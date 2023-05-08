class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int ans = 0;
        int i=0,j=0;
        while(i<m && j<n) 
        {
            ans += mat[i][j];
            i++;
            j++;
        }
        i=0,j=n-1;
        while(i<m && j>=0) 
        {
            ans += mat[i][j];
            i++;
            j--;
        }
        
        if(m%2 == 1) 
        {
            ans -= mat[m/2][n/2];
        }
        
        return ans;
    }
};