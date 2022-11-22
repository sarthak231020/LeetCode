class Solution {
public:
    
    bool solve(int i,int j,string &s,string &p,vector<vector<int>> &dp)
    {
        if(i == 0 && j == 0) // it means both are exhausted and matched
            return true;
        
        if(j == 0) 
        {
            return false;
        }
        if(i == 0) 
        {
            while(j-1 >= 0)
            {
                if(p[j-1] != '*')
                    return false;
                j--;
            }
            return true;
        }
        if(dp[i][j] != -1) 
            return dp[i][j];
        if(s[i-1] == p[j-1] || p[j-1] == '?') 
        {
            return dp[i][j] = solve(i-1,j-1,s,p,dp);
        }
        if(p[j-1] == '*')
        {
            return dp[i][j] = (solve(i-1,j,s,p,dp) | solve(i,j-1,s,p,dp));
        }
        
        //Means a mismatch so we can not overcome a mismatch.
        return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p) {
        int n1 = s.size(),n2 = p.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        return solve(n1,n2,s,p,dp);
        
        
    }
};