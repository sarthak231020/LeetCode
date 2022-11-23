class Solution {
public:
    
    int solve2dDp(int i,int tran,vector<int> &prices,vector<vector<int>> &dp) 
    {
        if(i >= prices.size()) 
        {
            return 0;
        }
        
        if(dp[i][tran] != -1) 
            return dp[i][tran];
        
        int profit = 0; 
        //tran is even (starting at 4) whenever we are allowed to buy.
        if(tran) //allowed to buy.
        {
            //1st case -> buy is completed so tran-1 so we are not allowed buy again until we sell that stock.
            //2nd case -> we have not buy that stock so we are allowed to buy next coming stocks.
            profit = max(-prices[i]+solve2dDp(i+1,0,prices,dp)
                         ,0+solve2dDp(i+1,1,prices,dp));
        }
        else
        {
            //1st case -> sell is completed so from next stock we are allowed to buy.
            //2nd case -> we are not selling the stock now we are not allowed to buy any other stock.
            profit = max(prices[i]+solve2dDp(i+2,1,prices,dp)
                         ,0+solve2dDp(i+1,0,prices,dp));
        }
        
        return dp[i][tran] = profit;
        
    }
    
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int> (2,-1));
        
        return solve2dDp(0,1,prices,dp);
    }
};