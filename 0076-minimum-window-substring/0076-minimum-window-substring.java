class Solution {

    public boolean contains(Map<Character,Integer> strMap,Map<Character,Integer> subStrMap)
    {
        for(Map.Entry<Character,Integer> entry:subStrMap.entrySet()) 
        {
            if(!strMap.containsKey(entry.getKey()))
                return false;
            if(strMap.get(entry.getKey()) < entry.getValue()) 
                return false;
        }
        return true;
    }

    public String minWindow(String s, String t) {
        if(t.length() > s.length())
            return "";
        int i = 0, j = 0, minLen = Integer.MAX_VALUE, n = s.length();
        int subCount = 0,mainCounter=0;
        int[] minWin = new int[2];
       // Map<Character,Integer> strMap = new HashMap<>();
        int[] strMap = new int[128];
        //Map<Character,Integer> subStrMap = new HashMap<>();
        int[] subStrMap = new int[128];
        for(char ch:t.toCharArray()){
            if(subStrMap[ch-'A']==0)
                subCount++;
            subStrMap[ch-'A']++;
        }
        System.out.println(subCount);
        while(j < n)
        {
            char rc = s.charAt(j);
            strMap[rc-'A']++;
            if(subStrMap[rc-'A']>0 && (strMap[rc-'A']==subStrMap[rc-'A']))
                mainCounter++;
            System.out.println(mainCounter);
            while(subCount==mainCounter)
            {
                if(j-i+1 < minLen) 
                {
                    minLen = j-i+1; 
                    minWin[0] = i; 
                    minWin[1] = j;
                }
                char lc = s.charAt(i);
                strMap[lc-'A']--;
                if( subStrMap[lc-'A']>0  && strMap[lc-'A']<subStrMap[lc-'A'])
                    mainCounter--;
                i++;
            }
            j++;
        }
        
        return minLen == Integer.MAX_VALUE ? "" : s.substring(minWin[0],minWin[1]+1);
    }
}