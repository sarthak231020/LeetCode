class Solution {

    public int maxPossible(int[] nums,int mid) 
    {
        int n = nums.length;
        long sum = 0;
        int parts = 1;
        for(int i=0;i<n;i++)
        {
            if(sum + (long)nums[i] <= mid)
            {
                sum += (long)(nums[i]);
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
        if(nums.length == k) 
            return Arrays.stream(nums).max().getAsInt();
        int low = Arrays.stream(nums).max().getAsInt(), high = Arrays.stream(nums).sum();
        int ans = -1;
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