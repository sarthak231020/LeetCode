class Solution {
public:
    
    int solve(int days,int ind,vector<int>& jobDifficulty,vector<vector<int>> &dp) 
    {
        if(ind == jobDifficulty.size() && days == 0) 
            return 0;
        if(ind == jobDifficulty.size() || days == 0) 
            return INT_MAX;
        if(dp[days][ind] != -1) 
            return dp[days][ind];
        int cur = jobDifficulty[ind];
        int mini = INT_MAX; 
        
        for(int schedule = ind;schedule<jobDifficulty.size();schedule++) 
        {
            cur = max(cur,jobDifficulty[schedule]); 
            int temp = solve(days-1,schedule+1,jobDifficulty,dp);
            if(temp != INT_MAX) 
                mini = min(mini,temp+cur);
        }
        
        return dp[days][ind] = mini;
    }
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        vector<vector<int>> dp(11,vector<int> (301,-1));
        int ans = solve(d,0,jobDifficulty,dp) ; 
        return ans == INT_MAX ? -1 : ans;
    }
};