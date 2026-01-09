class Solution {
    public boolean isValid(String s) {
        Deque<Character> st = new ArrayDeque<>();

        for(int i=0;i<s.length();i++) 
        {
            char currChar = s.charAt(i);
            if(currChar == '(' || currChar == '{' || currChar == '[')
                st.push(currChar);
            else  
            {
                if(st.isEmpty())
                    return false;
                else if((currChar==']' && st.peek() == '[') || (currChar==')' && st.peek() == '(') || (currChar=='}' && st.peek() == '{'))
                {
                    st.pop();
                }
                else
                    return false;
            }
        }
        
        return st.isEmpty();
    }
}