class Solution {

    public boolean brutSol(String s1,String s2) 
    {
        int m = s1.length();
        int n = s2.length();
        char[] s1Arr = s1.toCharArray();
        Arrays.sort(s1Arr);
        String sortedS1 = new String(s1Arr);

        for(int i=0;i<=n-m;i++)
        {
            char[] temp = s2.substring(i,i+m).toCharArray();
            Arrays.sort(temp);
            String sortedSubstr = new String(temp);
            if(sortedS1.equals(sortedSubstr))
                return true;
        }
        return false;
    }

    public boolean optimalSol(String s1,String s2) 
    {
        int m = s1.length();
        int n = s2.length();
        if(m > n) 
            return false;

        int[] freq1 = new int[26];
        int[] freq2 = new int[26];
        int matches = 0;

        for(int i=0;i<m;i++) 
        {
            freq1[s1.charAt(i)-'a']++;
            freq2[s2.charAt(i)-'a']++;
        }

        for(int i=0;i<26;i++) 
        {
            if(freq1[i] == freq2[i])
                matches++;
        }
        int l = 0, r = m;
        while(r < n)
        {
            if(matches == 26)
                return true;
            int indexR = s2.charAt(r)-'a';
            freq2[indexR]++;
            
            if(freq1[indexR] == freq2[indexR])
                matches++;
            else if(freq1[indexR]+1 == freq2[indexR])
                matches--;
            r++;
            
            int indexL = s2.charAt(l)-'a';
            freq2[indexL]--;
            if(freq1[indexL] == freq2[indexL])
                matches++;
            else if(freq1[indexL]-1 == freq2[indexL])
                matches--;
            l++;
        }

        return matches == 26 ? true : false;
    }

    public boolean checkInclusion(String s1, String s2) {
        // return brutSol(s1,s2);
        return optimalSol(s1,s2);
    }
}