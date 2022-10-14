class Solution {
public:
    
    int solve(vector<int> &nums,vector<vector<int>> &dp,int ind,int sum)
    {
        if(ind == 0) 
        {
            if(sum == 0 && nums[0] == 0)  
                return 2; //there are 2 ways for that index.
            if(sum == 0 || sum == nums[0]) 
                return 1; //there is only 1 way with any other integer.
            return 0; //sum is not satisfying so 0 ways.
        }
        if(dp[ind][sum] != -1) 
            return dp[ind][sum];
        
        int notTake = solve(nums,dp,ind-1,sum);
        int take = 0;
        if(nums[ind] <= sum) 
            take = solve(nums,dp,ind-1,sum-nums[ind]);
        return dp[ind][sum] = take+notTake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i=0;i<nums.size();i++) 
        {
            sum += nums[i];
        }
        if(nums.size() == 1 && abs(nums[0]) != abs(target))
            return 0;
        if(sum-target < 0 || (sum-target)%2) 
            return 0;
        
        vector<vector<int>> dp(20+1,vector<int> (1000+1,-1));
        
        
        return solve(nums,dp,nums.size()-1,(sum-target)/2);
        
//         for(int i=0;i<=N;i++) 
//         {
//             dp[i][0] = 1;
//         }
//         for(int j=1;j<=sum;j++) 
//         {
//             dp[0][j] = 0;
//         }
        
//         for(int i=1;i<=N;i++) 
//         {
//             for(int j=1;j<=sum;j++) 
//             {
//                 if(nums[i-1] > j) 
//                     dp[i][j] = dp[i-1][j];
//                 else 
//                     dp[i][j] = (dp[i-1][j] + dp[i-1][j-nums[i-1]]);
//             }
//         }
//         for(int i=0;i<=N;i++) 
//         {
//             for(int j=0;j<=sum;j++) 
//             {
//                 cout<<dp[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         cout<<endl;
        // int cnt = 0;
        // for(auto i:nums) 
        //     if(i == 0) 
        //         cnt++;
        // int addZeros = 0;
        // if(cnt > 0) 
        //     addZeros = pow(2,cnt)-1;
        // return dp[N][(target+sum)/2]+addZeros;
    }
};