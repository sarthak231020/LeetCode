class Solution {
    public boolean brut(String s,String goal) 
    {
        if(s.length() != goal.length()) 
            return false;
        for(int i=0;i<s.length();i++)
        {
            String rotatedString = s.substring(i)+s.substring(0,i);
            if(rotatedString.equals(goal)) 
                return true;
        }
        return false;
    }
    public boolean optimal(String s,String goal) 
    {
        if(s.length() != goal.length()) 
            return false; 
        return (s+s).contains(goal);
    }
    public boolean rotateString(String s, String goal) {
        // return brut(s,goal);
        return optimal(s,goal);
    }
}