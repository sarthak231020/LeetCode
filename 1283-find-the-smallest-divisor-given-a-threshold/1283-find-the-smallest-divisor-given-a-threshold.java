class Solution {

    public boolean isLesserOrEqualToThreshold(int[] nums,int threshold,int div) 
    {
        long sum = 0;
        for(int i:nums) 
        {
            sum += Math.ceil(i*1D/div);
        }
        return sum <= threshold;
    }

    public int smallestDivisor(int[] nums, int threshold) {
        int low = 1, high = 1;
        for(int i:nums) 
        {
            high = Math.max(high,i);
        }
        int ans = high;
        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if(isLesserOrEqualToThreshold(nums,threshold,mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid+1;
            }
        }

        return ans;
    }
}