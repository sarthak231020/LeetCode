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
    int solveTabulated(int amount, vector<int>& coins)
    {
        // cout<<"NEXT"<<endl;
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        
        //for all amount as 0 we should fill 1 since we are able to generate it no matter what.
        for(int i=0;i<n;i++) 
        {
            dp[i][0] = 1;
        }
        for(int amt = 1; amt <= amount; amt++) 
        {
            if(amt%coins[0] == 0) 
                dp[0][amt] = 1;
            else
                dp[0][amt] = 0;
        }
        for(int ind=1;ind<n;ind++)
        {
            for(int amt = 1;amt<=amount;amt++) 
            {
                int pick = 0;
                if(coins[ind] <= amt)
                {
                    pick = dp[ind][amt-coins[ind]];
                }
                int notPick = dp[ind-1][amt];

                dp[ind][amt] = pick+notPick;
                // cout<<ind<<" "<<amt<<" "<<min(pick,notPick)<<endl; 
            }
        }
        
        return dp[n-1][amount];
        
    }
    
    int solveTabulatedSpaceOpt(int amount, vector<int>& coins)
    {
        // cout<<"NEXT"<<endl;
        int n = coins.size();
        vector<int> prev(amount+1,0),curr(amount+1,0);
        
        //for all amount as 0 we should fill 1 since we are able to generate it no matter what.
        
        prev[0] = 1; 
        for(int amt = 1; amt <= amount; amt++) 
        {
            if(amt%coins[0] == 0) 
                prev[amt] = 1;
            else
                prev[amt] = 0;
        }
        
        for(int ind=1;ind<n;ind++)
        {
            curr[0] = 1;
            for(int amt = 1;amt<=amount;amt++) 
            {
                int pick = 0;
                if(coins[ind] <= amt)
                {
                    pick = curr[amt-coins[ind]];
                }
                int notPick = prev[amt];

                curr[amt] = pick+notPick;
                // cout<<ind<<" "<<amt<<" "<<min(pick,notPick)<<endl; 
            }
            prev = curr;
        }
        
        return prev[amount];
        
    }
    
    int change(int amount, vector<int>& coins) {
        /* FOR MEMOIZED CODE :- TC :- O(N*amount) SC :- O(N*amount)+O(stackSpace)
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return solve(n-1,amount,coins,dp);
        */
        
        /*TC :- O(N*amount) SC :- O(N*amount).
        //Tabulated Code:-
        return solveTabulated(amount,coins);
        */
        
        /*TC :- O(N*amount) SC:-(2*amount)*/
        return solveTabulatedSpaceOpt(amount,coins);
        
    }
};