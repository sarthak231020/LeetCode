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
    
    int numSquares(int n) {
        vector<int> perSq; // an array which will have perfect squares stored. 
        
        for(int i=1;i<=100;i++) 
        {
            perSq.push_back(i*i);
        }
        
        vector<vector<int>> dp(100,vector<int> (n+1,-1));
        
        return solve(99,n,perSq,dp);
        
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