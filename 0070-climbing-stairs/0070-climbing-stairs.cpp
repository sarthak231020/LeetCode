class Solution {
public:
    // Recursive Solution :- 
//     int solve(int n,vector<int> &dp) 
//     {
//         if( n < 0) 
//             return 0;
//         if(n == 0) 
//             return 1;
//         if(dp[n] != -1) 
//             return dp[n];
        
//         return dp[n] = solve(n-1,dp)+solve(n-2,dp);
        
//     }
    
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        // return solve(n,dp); 
        
        //Iterative Solution :- 
        // dp[0] = 1;
        // dp[1] = 1;
        // for(int i=2;i<=n;i++) 
        // {
        //     dp[i] = dp[i-1]+dp[i-2];
        // }
        // return dp[n];
        
        //Space Optimized Solution :- 
        if(n <= 1) 
            return 1;
        int prev2 = 1; // n == 0
        int prev1 = 1; // n == 1
        int curr;
        for(int i=2;i<=n;i++) 
        {
            curr = prev1+prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return curr;
    }
};