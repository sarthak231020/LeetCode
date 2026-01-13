class Solution {
    public int longestOnes(int[] nums, int k) {
        int l = 0, r = 0, n = nums.length;
        int zeros = 0,ans = 0;

        while(r < n) 
        {   
            if(nums[r] == 0) 
                zeros++;
            while(l <= r && zeros > k) 
            {
                if(nums[l] == 0) 
                    zeros--;
                l++;
            }
            ans = Math.max(ans,r-l+1);
            r++;
        }

        return ans;
    }
}