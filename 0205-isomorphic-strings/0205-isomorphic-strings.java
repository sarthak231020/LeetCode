class Solution {
    public boolean isIsomorphic(String s, String t) {
        if(s.length() != t.length()) 
            return false;
        Map<Character,Character> mapping = new HashMap<>();
        for(int i=0;i<s.length();i++) 
        {
            if(mapping.containsKey(s.charAt(i)))
            {
                if(mapping.get(s.charAt(i)) != t.charAt(i))
                    return false;
            }
            else
            {
                mapping.put(s.charAt(i),t.charAt(i));
            }
        }
        Map<Character,Character> oppMapping = new HashMap<>();
        
        for(Map.Entry<Character,Character> entry:mapping.entrySet())
        {
            char v = entry.getValue();
            char k = entry.getKey();
            
            if(oppMapping.containsKey(v))
            {
                if(oppMapping.get(v) != k)
                    return false;
            }
            else
                oppMapping.put(v,k);
        }
        
        return true;
    }
}