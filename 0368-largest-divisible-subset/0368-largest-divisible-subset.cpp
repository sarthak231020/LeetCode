class Solution {
public:
    vector<int> solveOpt(vector<int> &nums) 
    {
        int N = nums.size();
        vector<int> dp(N,1),parent(N,0);
        for(int i=0;i<N;i++) 
        {
            parent[i] = i;
        }
        for(int i=0;i<N;i++) 
        {
            for(int j=0;j<i;j++) 
            {
                if(nums[i] % nums[j] == 0) 
                {
                    if(dp[i] < 1+dp[j]) 
                    {
                        dp[i] = 1+dp[j];
                        parent[i] = j;
                    }
                }
            }
        }
        int maxi = 1;
        int maxind = 0;
        for(int i=0;i<N;i++) 
        {
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                maxind = i;
            }
        }
        //To Print the LIS 
        vector<int> ans;
        while(parent[maxind] != maxind) 
        {
            ans.push_back(nums[maxind]);
            maxind = parent[maxind];
        }
        ans.push_back(nums[maxind]);
        
        return ans;
    }
    
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        return solveOpt(nums);
        
        
    }
};