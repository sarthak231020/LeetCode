class Solution {
    public int subarraysWithKDistinct(int[] s, int k) {
        return atMostK(s,k)-atMostK(s,k-1);
    }

    public int atMostK(int[] nums,int k)
    {
        // code here
        int i=0,j=0,count = 0;
        Map<Integer,Integer> winMap = new HashMap<>();
        while(j<nums.length)
        {
            int rc = nums[j];
            winMap.put(rc,winMap.getOrDefault(rc,0)+1);
            while(winMap.size()>k){
                int lc = nums[i];
                winMap.put(lc,winMap.getOrDefault(lc,0)-1);
                if(winMap.get(lc)==0)
                    winMap.remove(lc);
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
    
    public int bruteForce(int[] nums,int k)
    {
        Map<Integer,Integer> winMap = new HashMap<>();
        int count = 0;
        for(int i=0;i<nums.length;i++)
        {
            for(int j=i;j<nums.length;j++)
            {
                winMap.put(nums[j],winMap.getOrDefault(nums[j],0)+1);
                if(winMap.size()==k)
                    count++;
            }
            winMap.clear();
        }
        return count;
    }
}