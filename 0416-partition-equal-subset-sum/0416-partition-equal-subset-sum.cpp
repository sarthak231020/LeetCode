class Solution {
public:
    //Recursive Code :- 
//     bool solve(int i,int sum,vector<int> &nums,vector<vector<int>> &dp) 
//     {
//         if(sum == 0) 
//             return dp[i][sum] = true; 
//         if(i == nums.size()) 
//             return false;
//         if(dp[i][sum] != -1) 
//             return dp[i][sum];
        
//         if(nums[i] > sum) 
//             return dp[i][sum] = solve(i+1,sum,nums,dp);
//         else 
//             return dp[i][sum] = solve(i+1,sum-nums[i],nums,dp) || solve(i+1,sum,nums,dp);
//         return false; //just to avoid compilation err.
//     }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) 
        {
            sum += nums[i];
        }
        
//         vector<vector<int>> dp(200,vector<int> (20000+1,-1));
        if(sum%2 == 1) //if sum is odd then it is not possible to partition array 
            return false;
        
//         return solve(0,sum/2,nums,dp);
        
        //Iterative Code :- Top Down DP 
        vector<vector<bool>> dp(nums.size()+1,vector<bool> (sum/2 + 1,-1));
        int N = nums.size();
        for(int i=0;i<N;i++) 
        {
            dp[i][0] = 1;
        }
        for(int j=1;j<=sum/2;j++) 
        {
            dp[0][j] = 0;
        }
        dp[0][0] = 1;
        
        for(int i=1;i<=N;i++) 
        {
            for(int j=1;j<=sum/2;j++) 
            {
                if(nums[i-1] > j) 
                    dp[i][j] = dp[i-1][j];
                else 
                    dp[i][j] = (dp[i-1][j] || dp[i-1][j-nums[i-1]]);
            }
        }
        
        return dp[N][sum/2];
        
    }
};