class Solution {

    public boolean ableToMakeMBouquets(int[] nums,int k,int m,int day)
    {
        int count = 0;
        for(int i:nums)
        {
            if(i <= day) 
            {
                count++;
                if(count == k)
                {
                    count = 0;
                    m--;
                }
            }
            else
            {
                count=0;
            }
        }

        return m <= 0;
    }

    public int minDays(int[] nums, int m, int k) {
        int n = nums.length;
        // It is not possible to make m bouquets since size is less
        if((long)m*(long)k > (long)n) 
        {
            return -1;
        }

        int low = nums[0], high = nums[0];
        for(int i:nums) 
        {
            low = Math.min(low,i);
            high = Math.max(high,i);
        }
        int ans = high;
        
        while(low <= high) 
        {
            int mid = low + (high - low)/2;

            if(ableToMakeMBouquets(nums,k,m,mid))
            {
                ans = mid;
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return ans;
    }
}