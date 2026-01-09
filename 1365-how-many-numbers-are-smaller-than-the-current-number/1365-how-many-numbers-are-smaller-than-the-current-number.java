class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] freq = new int[101];
        int[] prefix = new int[101];
        int[] output = new int[nums.length];

        for(int i:nums) 
        {
            freq[i]++;
        }
        prefix[0] = freq[0];
        for(int i=1;i<101;i++) 
        {
            prefix[i] = prefix[i-1]+freq[i];
        }

        for(int i=0;i<nums.length;i++)
        {
            if(nums[i] == 0)
                output[i] = 0;
            else
                output[i] = prefix[nums[i]-1];
        }
        return output;
    }
}