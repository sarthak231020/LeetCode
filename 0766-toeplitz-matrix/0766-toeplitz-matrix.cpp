class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int Rows = matrix.size();
        int Cols = matrix[0].size();
        for(int i=0;i<Cols;i++) 
        {
            int r = 0,c = i;
            int ele = matrix[r][c];
            while(r < Rows && c < Cols) 
            {
                if(ele != matrix[r][c]) 
                    return false;
                r++;
                c++;
            }
        }
        
        for(int i=1;i<Rows;i++) 
        {
            int r = i,c = 0; 
            int ele = matrix[r][c];
            while(r < Rows && c < Cols) 
            {
                if(ele != matrix[r][c]) 
                    return false;
                r++;
                c++;
            }
        }
        
        return true;
    }
};