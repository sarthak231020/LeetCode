class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ind = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(ind == 0) 
            return 0;
        if(nums[ind] == target) 
            return ind;
        
        return ind;
    }
};