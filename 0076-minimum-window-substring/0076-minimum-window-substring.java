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
        Map<Character,Integer> strMap = new HashMap<>();
        Map<Character,Integer> subStrMap = new HashMap<>();
        for(char ch:t.toCharArray()){
            if(subStrMap.getOrDefault(ch,0)==0)
                subCount++;
            subStrMap.put(ch,subStrMap.getOrDefault(ch,0)+1);
        }
        System.out.println(subCount);
        while(j < n)
        {
            char rc = s.charAt(j);
            strMap.put(rc,strMap.getOrDefault(rc,0)+1);
            if(subStrMap.containsKey(rc) && strMap.get(rc).equals(subStrMap.get(rc)))
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
                strMap.put(lc,strMap.getOrDefault(lc,0)-1);
                if( subStrMap.containsKey(lc)  && strMap.get(lc)<subStrMap.get(lc))
                    mainCounter--;
                if(strMap.get(lc) == 0) 
                    strMap.remove(lc);
                i++;
            }
            j++;
        }
        
        return minLen == Integer.MAX_VALUE ? "" : s.substring(minWin[0],minWin[1]+1);
    }
}