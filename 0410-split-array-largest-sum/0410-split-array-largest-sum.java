class Solution {

    public int maxPossible(int[] nums,int mid) 
    {
        int n = nums.length;
        long sum = 0;
        int parts = 1;
        for(int i=0;i<n;i++)
        {
            if(sum + nums[i] <= mid)
            {
                sum += nums[i];
            }
            else
            {
                sum = nums[i];
                parts++;
            }
        }

        return parts;
    }

    public int splitArray(int[] nums, int k) {
        int low = nums[0],high = 0;
        for(int i : nums) 
        {
            low = Math.max(low,i);
            high += i;
        }
        while(low <= high) 
        {
            int mid = low + (high - low)/2;
            int parts = maxPossible(nums,mid);
            if(parts > k) 
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }

        return low;
    }
}