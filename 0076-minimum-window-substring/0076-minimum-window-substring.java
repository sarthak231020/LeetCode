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
        int[] minWin = new int[2];
        Map<Character,Integer> strMap = new HashMap<>();
        Map<Character,Integer> subStrMap = new HashMap<>();
        for(char ch:t.toCharArray()) 
            subStrMap.put(ch,subStrMap.getOrDefault(ch,0)+1);
        
        while(j < n)
        {
            char rc = s.charAt(j);
            strMap.put(rc,strMap.getOrDefault(rc,0)+1);
            while(contains(strMap,subStrMap))
            {

                if(j-i+1 < minLen) 
                {
                    minLen = j-i+1; 
                    minWin[0] = i; 
                    minWin[1] = j;
                }
                char lc = s.charAt(i);
                strMap.put(lc,strMap.getOrDefault(lc,0)-1);
                if(strMap.get(lc) == 0) 
                    strMap.remove(lc);
                i++;
            }
            j++;
        }

        return minLen == Integer.MAX_VALUE ? "" : s.substring(minWin[0],minWin[1]+1);
    }
}