class Solution {
public:
    
    int solve(int ind1,int ind2,string s1,string s2,vector<vector<int>> &dp)
    {
        if(ind1 == 0 || ind2 == 0) 
            return 0;

        if(dp[ind1][ind2] != -1) 
            return dp[ind1][ind2];

        if(s1[ind1-1] == s2[ind2-1]) 
            return dp[ind1][ind2] = 1+solve(ind1-1,ind2-1,s1,s2,dp);
        else
            return dp[ind1][ind2] = max(solve(ind1-1,ind2,s1,s2,dp),solve(ind1,ind2-1,s1,s2,dp));

    }
    
    int solveTabulated(string s1,string s2) 
    {
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));

        for(int ind1=1;ind1<=n1;ind1++) 
        {
            for(int ind2=1;ind2<=n2;ind2++) 
            {
                if(s1[ind1-1] == s2[ind2-1]) 
                    dp[ind1][ind2] = 1+dp[ind1-1][ind2-1];
                else
                    dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
            }
        }
        return dp[n1][n2];
    }
    
    int solveTabulatedSpaceOpt(string s1,string s2) 
    {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> prev(n2+1,0),curr(n2+1,0);

        for(int ind1=1;ind1<=n1;ind1++) 
        {
            for(int ind2=1;ind2<=n2;ind2++) 
            {
                if(s1[ind1-1] == s2[ind2-1]) 
                    curr[ind2] = 1+prev[ind2-1];
                else
                    curr[ind2] = max(prev[ind2],curr[ind2-1]);
            }
            prev = curr;
        }
        return prev[n2];
    }
    
    int longestPalindromeSubseq(string s) {
        int n1 = s.size();
        string s1 = s;
        reverse(s1.begin(),s1.end());
        int n2 = n1;
        
    // vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
    
    /* Memoized Code TC -> O(n*m) SC -> O(n*m)+O(Stack Space->max(s1.size,s2.size)).*/
//     return solve(n1,n2,s,s1,dp);
    
    /*Tabulated TC -> O(n*m) SC->O(n*m) */
//     return solveTabulated(s,s1);
    
    /*Space Optimized TC -> O(n*m) SC->O(2*m)*/
    return solveTabulatedSpaceOpt(s,s1);
    }
};