class Solution {
public:
    
    int solve(int i,int j,vector<int> &nums,vector<vector<int>> &dp) 
    {
        if(i > j) 
            return 0;
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        int maxi = INT_MIN;
        for(int k=i;k<=j;k++) 
        {
            int ans = nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
            maxi = max(maxi,ans); 
        }
        return dp[i][j] = maxi;
    }
    
    int maxCoins(vector<int>& nums) {
        vector<int> v;
        v.push_back(1); // Just to avoid the complication of calculations.
        for(auto i:nums)
            v.push_back(i);
        v.push_back(1); // Just to avoid the complication of calculations.
        int N = nums.size();
        vector<vector<int>> dp(N+2,vector<int> (N+2,-1));
        return solve(1,v.size()-2,v,dp);
        
    }
};