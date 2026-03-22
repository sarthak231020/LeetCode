class Solution {
    public int minArrivalsToDiscard(int[] arrivals, int w, int m) {
        int n = arrivals.length;
        if(m == n) 
            return 0; // No need to remove any one.
        int[] discarded = new int[n];
        Map<Integer,Integer> mp = new HashMap<>();

        int i = 0, j = 0, ans = 0;

        while(j < n) 
        {
            mp.put(arrivals[j],mp.getOrDefault(arrivals[j],0)+1);
            if(j-i+1 > w) 
            {
                if(discarded[i] == 0)
                    mp.put(arrivals[i],mp.get(arrivals[i])-1);
                i++;
            }
            if(mp.get(arrivals[j]) > m) 
            {
                ans++;
                discarded[j] = 1;
                mp.put(arrivals[j],mp.get(arrivals[j])-1);
            }
            j++;
        }

        return ans;
    }
}