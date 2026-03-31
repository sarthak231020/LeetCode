class Solution {

    public boolean brut(String s,String t) 
    {
        // Length are same mentioned already.
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

    public boolean optimal(String s,String t) 
    {
        // Length are same mentioned already.
        int[] seen1 = new int[256];
        int[] seen2 = new int[256];
        int n = s.length();
        // Update position and check whether both chars have same positions
        // Positions we are updating to avoid 0(default).
        for(int i=0;i<n;i++) 
        {
            char ch1 = s.charAt(i);
            char ch2 = t.charAt(i);
            if(seen1[ch1] != seen2[ch2])
                return false;
            seen1[ch1] = i+1;
            seen2[ch2] = i+1;
        }

        return true;
    }

    public boolean isIsomorphic(String s, String t) {
        return optimal(s,t);
    }
}