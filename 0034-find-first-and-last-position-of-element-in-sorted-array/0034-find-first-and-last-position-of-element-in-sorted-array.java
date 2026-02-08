class Solution {

    public int binarySearch(int[] nums,int target,boolean forFirst) 
    {
        int n = nums.length;
        int low = 0, high = n-1;
        int ans = -1;

        while(low <= high) 
        {
            int mid = low + (high - low)/2;

            if(nums[mid] == target) 
            {
                ans = mid;
                if(forFirst) 
                    high = mid-1;
                else
                    low = mid+1;
            }
            else if(nums[mid] > target) 
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return ans;
    }

    public int[] searchRange(int[] nums, int target) {
        
        int first = -1, last = -1;

        first = binarySearch(nums,target,true);
        last = binarySearch(nums,target,false);

        return new int[] {first,last};
    }
}