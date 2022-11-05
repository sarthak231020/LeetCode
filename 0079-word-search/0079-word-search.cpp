class Solution {
public:
    bool dfs(int x,int y,int ind,vector<vector<int>> &visited,vector<vector<char>> &board,string word) 
    {
        
        if(ind == word.size()) 
            return true;
        if(x < 0 || x>=board.size() || y<0 || y>=board[0].size() || word[ind] != board[x][y] || visited[x][y] == 1) 
        {
            return false;
        }
        visited[x][y] = 1;
        bool res = (dfs(x,y-1,ind+1,visited,board,word) or dfs(x,y+1,ind+1,visited,board,word) or dfs(x-1,y,ind+1,visited,board,word) or dfs(x+1,y,ind+1,visited,board,word));
        visited[x][y] = 0;
        
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int> (n,0));
        //BRUT SOLUTION BACKTRACKING :- TC -> O(m*n*4^len(WORD)) SC :- (len(word) + (m*n))
        for(int x=0;x<m;x++) 
        {
            for(int y=0;y<n;y++) 
            {
                if(dfs(x,y,0,visited,board,word))
                    return true;
            }
        }
        return false;
        
    }
};