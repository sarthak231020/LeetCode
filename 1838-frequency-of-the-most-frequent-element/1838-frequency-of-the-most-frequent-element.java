class Solution {
        public int optimal(int[] nums,int k) 
    {
        Arrays.sort(nums);
        int n = nums.length;
        int res = 1, i = 0, j;
        long sum = 0;

        for(j=0;j<n;j++) 
        {
            sum += nums[j];

            while(sum+k < nums[j]*1L*(j-i+1))
            {
                sum -= nums[i];
                i += 1;
            }

            res = Math.max(res,(j-i+1));
        }

        return res;
    }
    public int maxFrequency(int[] nums, int k) {

        // return optimal(nums,k) 
        Arrays.sort(nums);
        int n = nums.length;
        long sum = 0;
        int ans = 1, i = 0, j = 0;
        while(j < n) 
        {
            sum += nums[j];
            while((j-i+1)*1L*nums[j] > sum+k)
                sum -= nums[i++];
            ans = Math.max(ans,j-i+1);
            j++;
        }
        return ans;
    }
}