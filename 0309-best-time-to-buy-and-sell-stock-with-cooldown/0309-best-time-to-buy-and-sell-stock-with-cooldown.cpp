class Solution {
public:
    
    int solve2dDp(int i,int buy,vector<int> &prices,vector<vector<int>> &dp) 
    {
        if(i >= prices.size()) 
        {
            return 0;
        }
        
        if(dp[i][buy] != -1) 
            return dp[i][buy];
        
        int profit = 0; 
        //tran is even (starting at 4) whenever we are allowed to buy.
        if(buy) //allowed to buy.
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
        
        return dp[i][buy] = profit;
        
    }
    
    int solve2dDpTabulated(vector<int> &prices) 
    {
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int> (2,0));
        
        //No need to write the base cases since we are already filling the dp array with 0s.
        
        for(int i=n-1;i>=0;i--) 
        {
            for(int buy=0;buy<=1;buy++) 
            {   
                int profit = 0; 
                //tran is even (starting at 4) whenever we are allowed to buy.
                if(buy) //allowed to buy.
                {
                    //1st case -> buy is completed so tran-1 so we are not allowed buy again until we sell that stock.
                    //2nd case -> we have not buy that stock so we are allowed to buy next coming stocks.
                    profit = max(-prices[i]+dp[i+1][0]
                                 ,0+dp[i+1][1]);
                }
                else
                {
                    //1st case -> sell is completed so from next stock we are allowed to buy.
                    //2nd case -> we are not selling the stock now we are not allowed to buy any other stock.
                    
                    profit = max(prices[i]+dp[i+2][1]
                             ,0+dp[i+1][0]);
                }

                dp[i][buy] = profit;   
            }
        }
        
        return dp[0][1];
    }
    
    int solveSpaceOpt(vector<int> &prices) 
    {
        int aheadBuy,aheadNotBuy,currBuy,currNotBuy,nextAheadBuy;
        aheadBuy = aheadNotBuy = 0;
        nextAheadBuy = 0;
        int n = prices.size();
        
        for(int i=n-1;i>=0;i--) 
        {
                
            //1st case -> buy is completed so tran-1 so we are not allowed buy again until we sell that stock.
            //2nd case -> we have not buy that stock so we are allowed to buy next coming stocks.
            currBuy = max(-prices[i]+aheadNotBuy
                         ,0+aheadBuy);

            //1st case -> sell is completed so from next stock we are allowed to buy.
            //2nd case -> we are not selling the stock now we are not allowed to buy any other stock.

            currNotBuy = max(prices[i]+nextAheadBuy
                     ,0+aheadNotBuy);
                
            nextAheadBuy = aheadBuy;
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
            
        }
        
        return aheadBuy;
    }
    
    int maxProfit(vector<int>& prices) {
        //Memoized :- TC :- O(N*2) SC:- O(N*2)+O(N).
        // vector<vector<int>> dp(prices.size()+1,vector<int> (2,-1));
        // return solve2dDp(0,1,prices,dp);
        
        //Tabulated :- TC:- O(N*2) SC:- (N*2).
        // return solve2dDpTabulated(prices);
        
        //Space Optimized TC:- O(N).SC:- O(1).
        return solveSpaceOpt(prices);
    }
};