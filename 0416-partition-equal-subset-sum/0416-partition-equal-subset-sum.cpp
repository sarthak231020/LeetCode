class Solution {
public:
    bool solve(int i,int k,vector<int> &arr,vector<vector<int>> &dp) 
    {
        if(k == 0) 
            return true; 
        if(i < 0 || k < 0)  
            return false;

        if(dp[i][k] != -1) 
            return dp[i][k]; 
        bool pick =solve(i-1,k-arr[i],arr,dp);
        if(pick == true) 
            return true;
        bool notPick = solve(i-1,k,arr,dp);
        if(notPick == true) 
            return true;

        return dp[i][k] = (pick || notPick);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num:nums) 
            sum += num; 
        if(sum%2 == 1)  //Since we can not factorize if sum is odd.
            return false;
        vector<vector<int>> dp(nums.size(),vector<int> (sum/2 + 1 , -1));
        return solve(nums.size()-1,sum/2,nums,dp);
    }
};