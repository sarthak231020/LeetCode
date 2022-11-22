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
    
    bool solveTabulated(string &s,string &p)
    {
        int n1 = s.size(); 
        int n2 = p.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        
        dp[0][0] = 1;
        
        for(int i=1;i<=n1;i++) //When j is 0 return false
        {
            dp[i][0] = 0;
        }
        
        for(int j=1;j<=n2;j++) 
        {
            bool flag = true;
            int k = j;
            while(k-1 >= 0)
            {
                if(p[k-1] != '*')
                {
                    flag = false;
                    break; 
                }
                k--;
            }
            dp[0][j] = flag; 
        }
        
        
        for(int i=1;i<=n1;i++) 
        {
            for(int j=1;j<=n2;j++) 
            {
                if(s[i-1] == p[j-1] || p[j-1] == '?') 
                {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*')
                {
                    dp[i][j] = (dp[i-1][j] | dp[i][j-1]);
                }
                else
                {   
                    //Means a mismatch so we can not overcome a mismatch.
                    dp[i][j] = false;
                }
            }
        }
        
        return dp[n1][n2];
    }
    
    bool isMatch(string s, string p) {
        int n1 = s.size(),n2 = p.size();
        
        //Memoized TC :- O(M*N) SC:- O(M*N)(DP ARRAY)+O(M+N)(ASS).
//         vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
//         return solve(n1,n2,s,p,dp);
        
        return solveTabulated(s,p);
        
        
    }
};