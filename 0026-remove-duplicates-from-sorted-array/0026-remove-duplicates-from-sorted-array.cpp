class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=0;j<nums.size();j++) 
        {
            if(j == 0 || nums[j] != nums[j-1])
            {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};