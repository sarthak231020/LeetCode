class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int n = nums.length;
        Map<Integer,Integer> freqMap = new HashMap<>();
        List<Integer>[] freqEle = new List[n+1];
        int[] res = new int[k];
        for(int i:nums) 
        {
            freqMap.put(i,freqMap.getOrDefault(i,0)+1);
        }

        
        for(int i=0;i<=n;i++) 
        {
            freqEle[i] = new ArrayList<>();
        }

        for(Map.Entry<Integer,Integer> entry:freqMap.entrySet())
        {
            freqEle[entry.getValue()].add(entry.getKey());
        }
        int ind = 0;
        for(int i=n;i>=0;i--)
        {
            
            for(int j=0;j<freqEle[i].size();j++)
            {
                res[ind++] = freqEle[i].get(j);
                if(ind == k) 
                {
                    return res;
                }
            }
        }
        return res;
    }
}