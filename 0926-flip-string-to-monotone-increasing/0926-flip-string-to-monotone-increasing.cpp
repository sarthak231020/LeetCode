class Solution {
public:
    
    int solve(int i,int &num,string &s,vector<int> &dp) 
    {
        if(i == 0)  // base case
            return 0;
        if(dp[i-1] != -1) 
            return dp[i];
        
        if(s[i-1] == '1') 
        {
            
            int flip = solve(i-1,num,s,dp); // it will require no flips.
            dp[i-1] = flip;
            num++;
            
        }
        else 
        {
            int withFlip = 1+solve(i-1,num,s,dp);
            dp[i-1] = min(num,withFlip);
        }
        
        return dp[i-1];
        
    }
    
    int minFlipsMonoIncr(string s) {
        vector<int> dp(s.length(),-1);
        int num = 0;
        return solve(s.length(),num,s,dp);
    }
};