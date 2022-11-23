class Solution {
public:
    
    int solve(int i,int buy,int cap,vector<int> &prices,vector<vector<vector<int>>> &dp) 
    {
        if(cap == 0) 
            return 0;
        if(i == prices.size()) 
            return 0;
        
        if(dp[i][buy][cap] != -1)
            return dp[i][buy][cap];
        
        int profit = 0;
        if(buy) 
        {   
            //1st case -> is we are buying that stock so buy = 0 and -prices[i](we have given that much money to buy it).
            //2nd case -> is we are just leaving that stock and looking ahead to get other good stocks.
            profit = max(-prices[i]+solve(i+1,0,cap,prices,dp)
                         ,0+ solve(i+1,1,cap,prices,dp));
        }
        else
        {
            //1st case -> is we are selling the stock so earning the price[i] and Buy & Sell is done so capacity decreases.
            //2nd Case -> is we are not selling it now so we move to next index with same parameters.
            profit = max(prices[i]+solve(i+1,1,cap-1,prices,dp)
                         ,0+solve(i+1,0,cap,prices,dp));
        }
        
        return dp[i][buy][cap] = profit;
    }
    
    int solveTabulated(vector<int> &prices) 
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(3,0)));
        //Converting the base case.
        
        for(int i=0;i<=n;i++) 
        {
            for(int buy=0;buy<=1;buy++) 
            {
                dp[i][buy][0] = 0; //when capacity is 0 
            }
        }
        
        for(int buy=0;buy<=1;buy++) 
        {
            for(int cap = 0;cap<=2;cap++) 
            {
                dp[n][buy][cap] = 0; // when we hit to i == n.
            }
        }
        
        for(int i=n-1;i>=0;i--) 
        {
            for(int buy=0;buy<=1;buy++) 
            {
                for(int cap=0;cap<=2;cap++) 
                {
                    int profit = 0;
                    if(buy) 
                    {   
                        //1st case -> is we are buying that stock so buy = 0 and -prices[i](we have given that much money to buy it).
                        //2nd case -> is we are just leaving that stock and looking ahead to get other good stocks.
                        profit = max(-prices[i]+dp[i+1][0][cap]
                                     ,0+ dp[i+1][1][cap]);
                    }
                    else
                    {
                        //1st case -> is we are selling the stock so earning the price[i] and Buy & Sell is done so capacity decreases.
                        //2nd Case -> is we are not selling it now so we move to next index with same parameters.
                        if(cap == 0) 
                            profit = 0+dp[i+1][0][cap];
                        else
                            profit = max(prices[i]+dp[i+1][1][cap-1]
                                         ,0+dp[i+1][0][cap]);
                    }

                    dp[i][buy][cap] = profit;
                }
            }
        }
        
        return dp[0][1][2];
    }
    
    int solveTabulatedSpaceOpt(vector<int> &prices) 
    {
        int n = prices.size();
        vector<vector<int>> next(2,vector<int>(3,0)),curr(2,vector<int>(3,0));
        //Converting the base case.
        
        for(int i=0;i<=n;i++) 
        {
            for(int buy=0;buy<=1;buy++) 
            {
                next[buy][0] = 0; //when capacity is 0 
            }
        }
        
        for(int buy=0;buy<=1;buy++) 
        {
            for(int cap = 0;cap<=2;cap++) 
            {
                next[buy][cap] = 0; // when we hit to i == n.
            }
        }
        
        for(int i=n-1;i>=0;i--) 
        {
            for(int buy=0;buy<=1;buy++) 
            {
                for(int cap=0;cap<=2;cap++) 
                {
                    int profit = 0;
                    if(buy) 
                    {   
                        //1st case -> is we are buying that stock so buy = 0 and -prices[i](we have given that much money to buy it).
                        //2nd case -> is we are just leaving that stock and looking ahead to get other good stocks.
                        profit = max(-prices[i]+next[0][cap]
                                     ,0+ next[1][cap]);
                    }
                    else
                    {
                        //1st case -> is we are selling the stock so earning the price[i] and Buy & Sell is done so capacity decreases.
                        //2nd Case -> is we are not selling it now so we move to next index with same parameters.
                        if(cap == 0) 
                            profit = 0+next[0][cap];
                        else
                            profit = max(prices[i]+next[1][cap-1]
                                         ,0+next[0][cap]);
                    }

                    curr[buy][cap] = profit;
                }
            }
            next = curr;
        }
        
        return next[1][2];
    }
    
    int solve2dDp(int i,int tran,vector<int> &prices,vector<vector<int>> &dp) 
    {
        if(i == prices.size() || tran == 0) 
        {
            return 0;
        }
        
        if(dp[i][tran] != -1) 
            return dp[i][tran];
        
        int profit = 0; 
        //tran is even (starting at 4) whenever we are allowed to buy.
        if(tran%2 == 0) //allowed to buy.
        {
            //1st case -> buy is completed so tran-1 so we are not allowed buy again until we sell that stock.
            //2nd case -> we have not buy that stock so we are allowed to buy next coming stocks.
            profit = max(-prices[i]+solve2dDp(i+1,tran-1,prices,dp)
                         ,0+solve2dDp(i+1,tran,prices,dp));
        }
        else
        {
            //1st case -> sell is completed so from next stock we are allowed to buy.
            //2nd case -> we are not selling the stock now we are not allowed to buy any other stock.
            profit = max(prices[i]+solve2dDp(i+1,tran-1,prices,dp)
                         ,0+solve2dDp(i+1,tran,prices,dp));
        }
        
        return dp[i][tran] = profit;
        
    }
    
    int solve2dDpTabulated(vector<int> &prices) 
    {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (5,0));
        
        //No need to fill up the base case since we have already filled up dp with zeros.
        for(int i=n-1;i>=0;i--) 
        {
            for(int tran=1;tran<=4;tran++) 
            {
                int profit = 0; 
                //tran is even (starting at 4) whenever we are allowed to buy.
                if(tran%2 == 0) //allowed to buy.
                {
                    //1st case -> buy is completed so tran-1 so we are not allowed buy again until we sell that stock.
                    //2nd case -> we have not buy that stock so we are allowed to buy next coming stocks.
                    profit = max(-prices[i]+dp[i+1][tran-1]
                                 ,0+dp[i+1][tran]);
                }
                else
                {
                    //1st case -> sell is completed so from next stock we are allowed to buy.
                    //2nd case -> we are not selling the stock now we are not allowed to buy any other stock.
                    profit = max(prices[i]+dp[i+1][tran-1]
                                 ,0+dp[i+1][tran]);
                }

                dp[i][tran] = profit;   
            }
        }
        
        return dp[0][4];
        
    }
    
    int solve2dDpSpaceOpt(vector<int> &prices) 
    {
        
        int n = prices.size();
        vector<int> next(5,0),curr(5,0);
        
        //No need to fill up the base case since we have already filled up dp with zeros.
        for(int i=n-1;i>=0;i--) 
        {
            for(int tran=1;tran<=4;tran++) 
            {
                int profit = 0; 
                //tran is even (starting at 4) whenever we are allowed to buy.
                if(tran%2 == 0) //allowed to buy.
                {
                    //1st case -> buy is completed so tran-1 so we are not allowed buy again until we sell that stock.
                    //2nd case -> we have not buy that stock so we are allowed to buy next coming stocks.
                    profit = max(-prices[i]+next[tran-1]
                                 ,0+next[tran]);
                }
                else
                {
                    //1st case -> sell is completed so from next stock we are allowed to buy.
                    //2nd case -> we are not selling the stock now we are not allowed to buy any other stock.
                    profit = max(prices[i]+next[tran-1]
                                 ,0+next[tran]);
                }

                curr[tran] = profit;   
            }
            next = curr;
        }
        
        return next[4];
        
    }
    
    int maxProfit(vector<int>& prices) {
        
        //Memoized TC :- O(N*2*3) SC:- O(N*2*3)(DP Array)+O(N)(stack Space).
        // vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>> (2,vector<int>(3,-1)));
        // return solve(0,1,2,prices,dp);
        
        //Tabulated :-  TC :- O(N*2*3) SC :- O(N*2*3)
        // return solveTabulated(prices);
        
        //Space Optimized :-  TC :- O(N*2*3) SC:- O(2*2*3) -> O(1).
        // return solveTabulatedSpaceOpt(prices);
        
        //Using 2d DP.
        //Memoized TC:- O(N*5). SC:- O(N*5)(DP ARRAY)+O(N)(ASS).
        // vector<vector<int>> dp(prices.size(),vector<int> (5,-1));
        // return solve2dDp(0,4,prices,dp);
        
        //Using 2d DP 
        //Tabulated TC:- O(N*5) SC :- O(N*5)
        // return solve2dDpTabulated(prices);
        
        //Using 2d DP 
        //Space Optimized :- TC:- O(N*5) SC:- O(2*5) //O(1).
        return solve2dDpSpaceOpt(prices);
        
    }
};