class Solution {
public:
    
    int solve(int ind,int amount,int N,vector<int> &coins,vector<vector<int>> &dp) 
    {
        if(amount == 0) 
        {
            if(ind == N) 
                return INT_MAX-1;
            else 
                return 0;
        }
        if(ind == N-1) 
        {
            if(amount%coins[N-1] == 0)
                return amount/coins[N-1];
            else 
                return INT_MAX-1;
        }
        if(dp[ind][amount] != -1) 
        {
            return dp[ind][amount];
        }
        
        int nonPick = solve(ind+1,amount,N,coins,dp);
        int pick = INT_MAX-1;
        if(coins[ind] <= amount) 
            pick = 1+solve(ind,amount-coins[ind],N,coins,dp);
        
        return dp[ind][amount] = min(pick,nonPick);
            
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(13,vector<int> (10000+1,-1));
        int ans = solve(0,amount,coins.size(),coins,dp);
        return ans == INT_MAX-1 ? -1 : ans;
    }
};