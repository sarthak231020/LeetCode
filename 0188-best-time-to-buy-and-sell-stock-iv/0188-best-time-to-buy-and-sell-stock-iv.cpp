class Solution {
public:
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
    
    int solve2dDpTabulated(vector<int> &prices,int k) 
    {
        
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int> (k*2+1,0));
        
        //No need to fill up the base case since we have already filled up dp with zeros.
        for(int i=n-1;i>=0;i--) 
        {
            for(int tran=1;tran<=k*2;tran++) 
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
        
        return dp[0][k*2];
        
    }
    
    int solve2dDpSpaceOpt(vector<int> &prices,int k) 
    {
        
        int n = prices.size();
        vector<int> next(k*2+1,0),curr(k*2+1,0);
        
        //No need to fill up the base case since we have already filled up dp with zeros.
        for(int i=n-1;i>=0;i--) 
        {
            for(int tran=1;tran<=(k*2);tran++) 
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
        
        return next[k*2];
        
    }
    
    int maxProfit(int k, vector<int>& prices) {
        
        //memoized code :- TC :- O(N*k) SC :- O(N*k)+O(N).
        // int n = prices.size();
        // vector<vector<int>> dp(n,vector<int> (k*2+1,-1));
        // return solve2dDp(0,k*2,prices,dp);
        
        //Tabulated code :- TC:- O(N*k) SC:- O(N*k).
        // return solve2dDpTabulated(prices,k);
        
        //Space Opt: - TC:- O(N*k) SC:- O(2*k) 
        return solve2dDpSpaceOpt(prices,k);
    }
};