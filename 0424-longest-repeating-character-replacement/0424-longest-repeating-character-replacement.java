class Solution {

    public int brutSol(String s,int k)
    {
        Map<Character,Integer> freq = new HashMap<>();
        int n = s.length(), l = 0, r = 0, maxF = 0;
        int ans = 0;

        // ABAB k = 2 --> BBBB       ABAB -----> ABAB ----> BBBB ----> 
        
        while(r < n) 
        {
            freq.put(s.charAt(r), freq.getOrDefault(s.charAt(r),0)+1);
            maxF = Math.max(maxF,freq.get(s.charAt(r)));

            if((r-l+1)-maxF <= k)
                ans = Math.max(ans,r-l+1);
            
            while((r-l+1)-maxF > k) 
            {
                freq.put(s.charAt(l),freq.get(s.charAt(l))-1);
                l++;
            }
            r++;  
        }
        return ans;
    }

    public int characterReplacement(String s, int k) {
        return brutSol(s,k);
    }
}