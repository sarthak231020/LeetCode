class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N,1),cnt(N,1);
        int maxi = 1;
        for(int i=0;i<N;i++) 
        {
            for(int j=0;j<i;j++) 
            {
                if(nums[i] > nums[j] && dp[i] < dp[j]+1)
                {
                    dp[i] = 1+dp[j];
                    cnt[i] = cnt[j];
                }
                else if(nums[i] > nums[j] && dp[i] == dp[j]+1) 
                {
                    cnt[i] += cnt[j];
                }
            }
            maxi = max(maxi,dp[i]);
        }
        
        int ans = 0;
        for(int i=0;i<N;i++)
        {
            if(dp[i] == maxi)   
            {
                ans += cnt[i];
            }
        }
        return ans;
    }
};