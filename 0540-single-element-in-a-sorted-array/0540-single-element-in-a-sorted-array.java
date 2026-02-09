class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;

        if(n == 1) 
            return nums[0];
        if(nums[0] != nums[1]) 
            return nums[0];
        if(nums[n-1] != nums[n-2]) 
            return nums[n-1];

        int low = 1, high = n-2;
        // Approach is simple 

        //  left half --> even index (first appearance) odd index (second appearance).
        // (since single element break that chain) so -----> right half --> odd index (first appearance) even index (second appearance).
        while(low <= high) 
        {
            int mid = low + (high-low)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];
            if(mid%2 == 0)
            {
                if(nums[mid] == nums[mid+1])
                    low = mid+1;
                else
                    high = mid-1;
            }
            else
            {
                if(nums[mid] == nums[mid-1])
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return -1;
    }
}