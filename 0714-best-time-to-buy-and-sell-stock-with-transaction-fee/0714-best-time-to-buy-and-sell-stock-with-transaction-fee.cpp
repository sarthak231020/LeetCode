class Solution {
public:
    int solve2dDp(int i,int buy,int fee,vector<int> &prices,vector<vector<int>> &dp) 
    {
        if(i >= prices.size()) 
        {
            return 0;
        }
        
        if(dp[i][buy] != -1) 
            return dp[i][buy];
        
        int profit = 0; 
        if(buy) //allowed to buy.
        {
            //1st case -> buy is completed so we are not allowed to buy again 
            //2nd case -> we have not buy that stock so we are allowed to buy next coming stocks.
            profit = max(-prices[i]+solve2dDp(i+1,0,fee,prices,dp)
                         ,0+solve2dDp(i+1,1,fee,prices,dp));
        }
        else
        {
            //1st case -> sell is completed so from next stock we are allowed to buy.
            //2nd case -> we are not selling the stock now we are not allowed to buy any other stock.
            profit = max(prices[i]-fee+solve2dDp(i+1,1,fee,prices,dp)
                         ,0+solve2dDp(i+1,0,fee,prices,dp));
        }
        
        return dp[i][buy] = profit;
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        
        vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
        return solve2dDp(0,1,fee,prices,dp);
        
    }
};