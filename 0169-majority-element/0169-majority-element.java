class Solution {

    public int brut(int[] nums) 
    {
        int n = nums.length;
        Map<Integer,Integer> freq = new HashMap<>();

        for(int i:nums) 
            freq.put(i,freq.getOrDefault(i,0)+1);
        
        return freq.entrySet()
           .stream()
           .filter(e -> e.getValue() > n / 2)
           .map(Map.Entry::getKey)
           .findFirst()
           .orElse(-1);
    }

    public int optimal(int[] nums)
    {
        // Moore's Algorithm
        // Says pick a elements keep increasing count if element matches.
        // else keep decreasing count if element does not match.
        // we need to verify if problem does not state there always be a majority element.
        int n = nums.length;
        int cnt = 0, ele=nums[0];
        for(int i=0;i<n;i++) 
        {
            if(cnt == 0) 
            {
                ele = nums[i];
                cnt++;
            }
            else if(ele == nums[i])
                cnt++;
            else
                cnt--;
        }

        // If always a mojority element exist there no need to verify 
        return ele;
        // Otherwise we have to verify it 
        // Dry run 
        // 7 7 5 7 5 1 5 7 5 5 7 7 1 1 1 1 -- in this case ele will point to 1 which is not majority element.
        // int cnt1 = 0;
        // for(int i:nums)
        //     if(i == ele) 
        //         cnt1++;
        // return cnt1 > n/2 ? ele : -1;
    }

    public int majorityElement(int[] nums) {
        return optimal(nums);
    }
}