class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long res = 0,sum = 0;
        
        for(int i=0;i<nums.size();i++) 
        {
            sum += nums[i];
            // sum+i is used here for ceiling the value.
            res = max(res,(sum+i)/(i+1)); // result will store the average 
        }
        return res; 
    }
};