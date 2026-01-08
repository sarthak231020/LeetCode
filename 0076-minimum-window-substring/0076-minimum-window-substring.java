class Solution {

    public int[] populateFreq(String s)
    {
        int[] freq = new int[256];

        for(int i=0;i<s.length();i++) 
        {
            freq[s.charAt(i)-'A']++;
        }

        return freq;
    }

    public boolean checkIfSubstr(String s1,String s2,int[] freq1,int[] freq2)
    {
        // check if s2 all things covered in s1 or not.

        for(int i=0;i<s2.length();i++) 
        {
            int currChar = s2.charAt(i);
            if(freq1[currChar-'A'] < freq2[currChar-'A'])
                return false;
        }
        return true;
    }

    public String brutSol(String s,String t) 
    {
        int m = s.length();
        int n = t.length();
        if(n > m) 
            return "";
        
        int ansL = Integer.MIN_VALUE;
        int ansR = Integer.MAX_VALUE;
        int minLen = Integer.MAX_VALUE;

        int freq1[] = new int[256];
        int freq2[] = new int[256];

        for(int i=0;i<n;i++) 
        {
            freq2[t.charAt(i)-'A']++;
        }

        for(int i=0;i<m;i++) 
        {
            for(int j=i+1;j<=m;j++) 
            {
                if(j-i+1 >= n)
                {
                    String currSubStr = s.substring(i,j);
                    freq1 = populateFreq(currSubStr);
                    
                    if(checkIfSubstr(currSubStr,t,freq1,freq2))
                    {
                        // System.out.println(currSubStr + " " + t);
                        if(j-i+1 < minLen)
                        {
                            minLen = j-i+1;
                            ansL = i;
                            ansR = j;
                        }
                    }
                }
            }
        }
        if(minLen == Integer.MAX_VALUE)
            return "";
        return s.substring(ansL,ansR);
    }


    public String optimalSol(String s,String t) 
    {
        int m = s.length();
        int n = t.length();

        if(n > m)
            return "";
        
        Map<Character,Integer> countT = new HashMap<>();
        Map<Character,Integer> window = new HashMap<>(); 

        for(int i=0;i<n;i++) 
        {
            Character currChar = t.charAt(i);
            countT.put(currChar,countT.getOrDefault(currChar,0)+1);
        }

        int need = countT.size(), have = 0, resLen = Integer.MAX_VALUE, ansL = 0,ansR = 0;
        int l = 0, r = 0;

        while(r < m) 
        {
            char currChar = s.charAt(r);
            window.put(currChar,window.getOrDefault(currChar,0)+1);
            if(countT.containsKey(currChar) && countT.get(currChar).equals(window.get(currChar))) 
            {
                have++;
            }   
            r++;

            while(have == need) 
            {
                if(r-l+1 < resLen)
                {
                    resLen = r-l+1;
                    ansL = l;
                    ansR = r;
                }
                window.put(s.charAt(l),window.getOrDefault(s.charAt(l),0)-1);
                if(countT.containsKey(s.charAt(l)) && window.get(s.charAt(l)) < countT.get(s.charAt(l)))
                {
                    have--;
                }
                l++;
            }
        }

        return resLen == Integer.MAX_VALUE ? "" : s.substring(ansL,ansR);
        
    }

    public String minWindow(String s, String t) {
        // return brutSol(s,t);
        return optimalSol(s,t);
    }
}