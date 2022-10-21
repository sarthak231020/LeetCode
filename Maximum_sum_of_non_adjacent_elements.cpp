#include <bits/stdc++.h> 
int solve(int ind,vector<int> &nums,vector<int> &dp)
{
    if(ind == 0)  //it will be called in case of ind == 2
        return nums[ind];
    if(ind < 0) 
        return 0; //since it will be out of bound so return 0
    if(dp[ind] != -1) 
        return dp[ind];
    
    int pick = nums[ind] + solve(ind-2,nums,dp); // Since we have picked current element so omit picking the adjacent element.
    int notPick = 0 + solve(ind-1,nums,dp); //Since we are omitting current element so we are allowed to pick its adjacent element
    
    return dp[ind] = max(pick,notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size()+1,-1);
    
//     return solve(nums.size()-1,nums,dp);
//     dp[0] = nums[0];
//     dp[1] = max(nums[0],nums[1]);
//     for(int i=2;i<nums.size();i++) 
//     {
//         int pick = nums[i]+dp[i-2];
//         int notPick = 0 + dp[i-1];
        
//         dp[i] = max(pick,notPick);
//     }
    
//     return dp[nums.size()-1];
    
    //Optimized Code :- 
    int prev2 = nums[0];
    int prev1 = max(nums[0],nums[1]);
    int N = nums.size();
    if(N == 1) 
        return prev2; 
    if(N == 2)
        return prev1;
    int curr;
    for(int i=2;i<N;i++) 
    {
         int pick = nums[i]+prev2;
         int notPick = 0+prev1;
         curr = max(pick,notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    
    return curr;
    // Write your code here.
}
