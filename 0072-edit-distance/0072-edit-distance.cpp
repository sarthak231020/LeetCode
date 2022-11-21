class Solution {
public:
    
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(i < 0) 
            return j+1; //if s1 get exhausted then we need to insert j+1 characters to make it equal to s2.
        if(j < 0) 
            return i+1; //if s2 get exhausted then we need to delete i+1 characters from s1 to make it empty.
        
        if(dp[i][j] != -1) 
            return dp[i][j]; // if we have already calculated it no need to recalculate just return.
        
        if(s1[i] == s2[j]) 
            return dp[i][j] = solve(i-1,j-1,s1,s2,dp); //this means we have to do nothing since it is already a match.
        
        int ans = 0;
        
        int insert = 1+solve(i,j-1,s1,s2,dp); // we have inserted the char just after the ith index in s1 so i will remain at same position and since we obviously inserted the s2[j] character so we have matched the s1[i+1] && s2[j] (hypothetically i.e. we are not inserting anything here).
        int del = 1 + solve(i-1,j,s1,s2,dp); // since we have deleted s1[i] so just move the i since we still want a match to j.  (hypothetically i.e. we are not deleting anything here).
        int replace = 1 + solve(i-1,j-1,s1,s2,dp); // since we have replaced the s1[i] by s2[j] so just move both the indices i-1,j-1.
        
        ans = min(insert,min(del,replace));
        
        return dp[i][j] = ans;
        
    }
    
    int solveTabulated(string &s1,string &s2,int n1,int n2)  
    {
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        
        for(int i=0;i<=n1;i++) 
        {
            dp[i][0] = i; 
        }
        
        for(int j=0;j<=n2;j++) 
        {
            dp[0][j] = j;
        }
        dp[0][0] = 0; // both are exhausted then no need to do anything.
        
        for(int i=1;i<=n1;i++) 
        {
            for(int j=1;j<=n2;j++) 
            {
                if(s1[i-1] == s2[j-1]) 
                {
                    dp[i][j] = dp[i-1][j-1]; //this means we have to do nothing since it is already a match.
                }
                else
                {
                    int ans = 0;

                    int insert = 1+solve(i,j-1,s1,s2,dp); // we have inserted the char just after the ith index in s1 so i will remain at same position and since we obviously inserted the s2[j] character so we have matched the s1[i+1] && s2[j] (hypothetically i.e. we are not inserting anything here).
                    int del = 1 + solve(i-1,j,s1,s2,dp); // since we have deleted s1[i] so just move the i since we still want a match to j.  (hypothetically i.e. we are not deleting anything here).
                    int replace = 1 + solve(i-1,j-1,s1,s2,dp); // since we have replaced the s1[i] by s2[j] so just move both the indices i-1,j-1.

                    ans = min(insert,min(del,replace));
                    dp[i][j] = ans;
                }
            }
        }
        return dp[n1][n2];
    }
    
    int minDistance(string s1, string s2) {
        
        int n1 = s1.size();
        int n2 = s2.size();
        // vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        // return solve(n1-1,n2-1,s1,s2,dp);
        
        return solveTabulated(s1,s2,n1,n2);
    }
};