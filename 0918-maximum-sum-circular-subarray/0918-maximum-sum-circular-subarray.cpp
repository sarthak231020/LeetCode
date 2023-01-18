class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> rightMax(n); //It will be storing the maximum of the suffix sum till ith index.
        
        rightMax[n-1] = nums[n-1];
        int suffixSum = nums[n-1];
        for(int i=n-2;i>=0;i--) 
        {
            suffixSum = suffixSum+nums[i];
            rightMax[i] = max(rightMax[i+1],suffixSum);
        }
        
        int prefixSum = 0,specialSum = nums[0];
        int max_so_far = 0,max_ending_here = INT_MIN;
        for(int i=0;i<n;i++) 
        {
            max_so_far = max(max_so_far,0) + nums[i];
            max_ending_here = max(max_so_far,max_ending_here);
            prefixSum += nums[i];
            if(i+1 < n) 
            {
                specialSum = max(specialSum,prefixSum + rightMax[i+1]);
            }
        }
        
        return max(max_ending_here,specialSum);
    }
};