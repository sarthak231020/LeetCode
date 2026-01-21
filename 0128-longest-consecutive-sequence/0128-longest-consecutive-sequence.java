class Solution {

    public int brut(int[] nums) 
    {
        if(nums.length == 0) 
            return 0;
        Arrays.sort(nums);
        int cnt = 1, ans = 1;

        for(int i=1;i<nums.length;i++)
        {
            if(nums[i-1] == nums[i]) 
                continue;
            if(nums[i-1]+1 == nums[i])
                cnt++;
            else
                cnt = 1;
            ans = Math.max(cnt,ans);
        }
        return ans;
    }   
    public int optimal(int[] nums)
    {
        if(nums.length == 0) 
            return 0;
        Set<Integer> st = new HashSet<>();
        int cnt = 1,ans = 1;

        for(int i:nums) 
        {
            st.add(i);
        }

        for(int i:st)
        {
            if(!st.contains(i-1)) 
            {
                cnt = 1;
                int currVal = i+1;
                while(st.contains(currVal))
                {
                    cnt += 1;
                    currVal++;
                }
                ans = Math.max(ans,cnt);
            }
        }

        return ans;
    }
    public int longestConsecutive(int[] nums) {
        // return brut(nums);
        return optimal(nums);
    }
}