class Solution {
    public int myAtoi(String s) {
        long ans = 0;
        long sign = 1;
        s = s.strip();
        if(s.length() == 0) 
            return 0;
        int i = 0;
        if(s.charAt(i) == '-' || s.charAt(i) == '+')
        {
            if(s.charAt(i) == '-')
                sign = -1;
            i++;
        }
        while(i < s.length() && s.charAt(i) == '0')
        {
            i++;
        }
        while(i < s.length() && Character.isDigit(s.charAt(i)))
        {
            ans = ans*10+Integer.valueOf(s.charAt(i)-'0');
            if(ans*sign > Integer.MAX_VALUE) 
                return Integer.MAX_VALUE;
            if(ans*sign < Integer.MIN_VALUE) 
                return Integer.MIN_VALUE;
            i++;
        }
        return (int)(ans*sign);
    }
}