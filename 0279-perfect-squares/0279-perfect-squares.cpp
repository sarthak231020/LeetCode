class Solution {
public:
    
    int solve(int i,int n,vector<int> &perSq,vector<vector<int>> &dp) 
    {
        if(n == 0) 
            return 0;
        if(i == 0) 
        {
            if(n%perSq[i] == 0) 
            {
                return n/perSq[i];
            }
            else
            {
                return 1e9; // we are not able to consume the n.
            }
        }
        
        if(dp[i][n] != -1) 
            return dp[i][n];
        
        int pick = 1e9; 
        if(perSq[i] <= n)
            pick = 1+solve(i,n-perSq[i],perSq,dp);
        int notPick = solve(i-1,n,perSq,dp);
        
        return dp[i][n] = min(pick,notPick);
    }
    
    int solveSpaceOpt(vector<int> &perSq,int n)
    {
        vector<int> prev(n+1,0),curr(n+1,0);
        
        for(int j=1;j<=n;j++) 
        {
            if(n%perSq[0] == 0) 
            {
                prev[j] = n/perSq[0];
            }   
            else 
            {
                prev[j] = 1e9;
            }
        }
        prev[0] = 0; 
        
        for(int i=1;i<=perSq.size();i++) 
        {
            curr[0] = 0; // when n is zero the result is 0.
            for(int j=1;j<=n;j++) 
            {
                int pick = 1e9; 
                if(j-perSq[i-1] >= 0)
                    pick = 1+curr[j-perSq[i-1]];
                int notPick = prev[j];

                curr[j] = min(pick,notPick);
            }
            prev = curr;
        }
        return prev[n];
    }
    
    int numSquares(int n) {
        vector<int> perSq; // an array which will have perfect squares stored. 
        
        for(int i=1;i*i<=n;i++) 
        {
            perSq.push_back(i*i);
        }
        
        // FOR MEMOIZED CODE 
//         vector<vector<int>> dp(perSq.size(),vector<int> (n+1,-1));
//         return solve(perSq.size()-1,n,perSq,dp);
        
        return solveSpaceOpt(perSq,n);
        
//         int ans = 0;
//         for(int i=99;i>=0;i--) 
//         {
//             if(n%perSq[i] == 0) 
//             {
//                 ans += (n/perSq[i]);
//                 break;
//             }
//             else
//             {
                
//             }
//         }
    }
};