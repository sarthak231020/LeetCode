class Solution {
public:
    
    int solve(int ind,int amount, vector<int>& coins,vector<vector<int>> &dp)  
    {
        if(amount == 0)
            return 1; //there is always possible to generate the amount = 0
        if(ind == 0)  //coins[i] is never be 0 as per constraints.
        {
            if(amount%coins[0] == 0) 
                return 1; 
            else
                return 0; //not possible to generate the amount
        }
        if(dp[ind][amount] != -1) 
            return dp[ind][amount];
        int pick = 0;
        if(coins[ind] <= amount) 
            pick = solve(ind,amount-coins[ind],coins,dp);
        int notPick = solve(ind-1,amount,coins,dp);
        
        return dp[ind][amount] = (pick+notPick);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        
        return solve(n-1,amount,coins,dp);
        
    }
};