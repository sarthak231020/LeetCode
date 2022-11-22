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
    
    int solveDpTabulated(vector<int> &prices) 
    {
        int n = prices.size();
        
        vector<vector<int>> dp(n+1,vector<int> (2,0));
        
        //Converting the base case.
        dp[n][0] = 0;
        dp[n][1] = 0; 
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                int profit = 0;
                if(buy) // means if we are allowed to buy then it's our choice to buy or not.
                {
                    profit = max(-prices[i]+dp[i+1][0],0+dp[i+1][1]);
                    // first case we are buying it using it's price so -prices[i] and going forward to not buy it again
                    //Second Case we are not buying and can buy other stocks(passing buy = 1).

                }
                else
                {
                    //again we have two choices either we are selling it now pr may be we will sell it later.
                    //First case we allow to buy again 
                    //Second Case we won't allow to buy 
                    profit = max(prices[i]+dp[i+1][1],0+dp[i+1][0]);

                }

                dp[i][buy] = profit;
            }   
        }
        
        return dp[0][1]; // as we know we are passing 1 initially.
        
    }
    
    int solveDpTabulatedSpaceOpt(vector<int> &prices) 
    {
        int n = prices.size();
        
        vector<int> nex(2,0),curr(2,0);
        
        //Converting the base case.
        nex[0] = 0;
        nex[1] = 0; 
        
        for(int i=n-1;i>=0;i--)
        {
            for(int buy = 0;buy<=1;buy++)
            {
                int profit = 0;
                if(buy) // means if we are allowed to buy then it's our choice to buy or not.
                {
                    profit = max(-prices[i]+nex[0],0+nex[1]);
                    // first case we are buying it using it's price so -prices[i] and going forward to not buy it again
                    //Second Case we are not buying and can buy other stocks(passing buy = 1).

                }
                else
                {
                    //again we have two choices either we are selling it now pr may be we will sell it later.
                    //First case we allow to buy again 
                    //Second Case we won't allow to buy 
                    profit = max(prices[i]+nex[1],0+nex[0]);

                }

                curr[buy] = profit;
            }   
            nex = curr;
        }
        
        return nex[1]; // as we know we are passing 1 initially.       
    }
    
    int solveDpVar(vector<int> &prices) 
    {
        int n = prices.size();
        
        int nextBuy,nextNotBuy,currBuy,currNotBuy;
        
        //Converting the base case.
        nextBuy = 0;
        nextNotBuy = 0; 
        
        for(int i=n-1;i>=0;i--)
        {
             // first case we are buying it using it's price so -prices[i] and going forward to not buy it again
            //Second Case we are not buying and can buy other stocks(passing buy = 1).
            
            currBuy = max(-prices[i]+nextNotBuy,0+nextBuy);
            
            //again we have two choices either we are selling it now pr may be we will sell it later.
            //First case we allow to buy again 
            //Second Case we won't allow to buy 
            currNotBuy = max(prices[i]+nextBuy,0+nextNotBuy);

            nextBuy = currBuy;
            nextNotBuy = currNotBuy;
        }
        
        return nextBuy; // as we know we are passing 1 initially.       
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        //Greedy Solution:- TC:- O(N) SC:- O(1).
                                                //    buy have two states 0 and 1 only
        //Memoized Solution:- TC:- O(N*2) SC:- O(N*2)(DP ARRAY)+O(N) (Aux Stack Space Since we hit the base case after the N rec call)
        // vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
        // return solveDp(0,1,prices,dp);
        
        //Tabulated Solution :- TC:- O(N*2). SC:- O(N*2).
        // return solveDpTabulated(prices);
        
        //Space Optimized Solution :- TC :- O(N*2) SC:- O(1). 
        // return solveDpTabulatedSpaceOpt(prices);
        
        //Space Optimized Variable Solution :- TC :- O(N) SC:- O(1).
        return solveDpVar(prices);
        
    }
};