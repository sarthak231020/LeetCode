class Solution {
public:
    
    int solveGreedy(vector<int> &prices)
    {
        int profit = 0;
        
        for(int i=1;i<prices.size();i++) 
        {
            if(prices[i] > prices[i-1]) 
            {
                profit += (prices[i]-prices[i-1]);
            }
        }
        return profit;
    }
                // index  buy=1(means you are allowed to buy) and (buy = 0 means you are not allowed to buy).
    int solveDp(int i,int buy,vector<int> &prices,vector<vector<int>> &dp) 
    {
        if(i == prices.size()) 
        {
            return 0; // no matter what you are holding you can't sell it now 
        }
        
        if(dp[i][buy] != -1) 
            return dp[i][buy];
        
        int profit = 0;
        if(buy) // means if we are allowed to buy then it's our choice to buy or not.
        {
            profit = max(-prices[i]+solveDp(i+1,0,prices,dp),0+solveDp(i+1,1,prices,dp));
            // first case we are buying it using it's price so -prices[i] and going forward to not buy it again
            //Second Case we are not buying and can buy other stocks(passing buy = 1).
            
        }
        else
        {
            //again we have two choices either we are selling it now pr may be we will sell it later.
            //First case we allow to buy again 
            //Second Case we won't allow to buy 
            profit = max(prices[i]+solveDp(i+1,1,prices,dp),0+solveDp(i+1,0,prices,dp));
            
        }
        
        return dp[i][buy] = profit;
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        //Greedy Solution:- TC:- O(N) SC:- O(1).
                                                //    buy have two states 0 and 1 only
        vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
        return solveDp(0,1,prices,dp);
    }
};