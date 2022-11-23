class Solution {
public:
    
    
    bool isValid(vector<vector<char>> &board,int row,int col)
    {
        char c = board[row][col];
        // cout<<c<<endl;
        // board[row][col] = '.';
        for(int j=0;j<=8;j++) 
        {
            // cout<<board[row][col]<<endl;
            if(board[row][j] == c && j != col) 
                return false;
            if(board[j][col] == c && j != row) 
                return false;
            int ro = (3*(row/3)+(j/3));
            int co = (3*(col/3)+(j%3));
            if(!(ro == row && co == col) && (board[ro][co] == c))
                return false;
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        
        int rows = board.size();
        int cols = board[0].size();
        
        for(int i=0;i<rows;i++) 
        {
            for(int j=0;j<cols;j++) 
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                else
                {
                    if(isValid(board,i,j) == false) 
                        return false;
                }
            }
        }
        
        return true;
        
    }
};










