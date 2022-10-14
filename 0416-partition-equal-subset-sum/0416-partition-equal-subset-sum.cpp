class Solution {
public:
    bool solve(int i,int sum,vector<int> &nums,vector<vector<int>> &dp) 
    {
        if(sum == 0) 
            return dp[i][sum] = true; 
        if(i == nums.size()) 
            return false;
        if(dp[i][sum] != -1) 
            return dp[i][sum];
        
        if(nums[i] > sum) 
            return dp[i][sum] = solve(i+1,sum,nums,dp);
        else 
            return dp[i][sum] = solve(i+1,sum-nums[i],nums,dp) || solve(i+1,sum,nums,dp);
        return false; //just to avoid compilation err.
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) 
        {
            sum += nums[i];
        }
        
        vector<vector<int>> dp(200,vector<int> (20000+1,-1));
        if(sum%2 == 1) //if sum is odd then it is not possible to partition array 
            return false;
        
        return solve(0,sum/2,nums,dp);
    }
};