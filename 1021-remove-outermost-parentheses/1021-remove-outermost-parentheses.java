class Solution {
    public String removeOuterParentheses(String s) {
        int cnt = 0;
        int start = 0;
        StringBuilder ans = new StringBuilder();
        for(int i=0;i<s.length();i++) 
        {
            if(s.charAt(i) == '(')
            {
                if(cnt == 0) 
                    start = i+1;
                cnt++;
            }
            if(s.charAt(i) == ')') 
                cnt--;
            if(cnt == 0) 
            {

                ans.append(s.substring(start,i));
            }
        }

        return ans.toString();
    }
}