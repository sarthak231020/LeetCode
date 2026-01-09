class Solution {

    public boolean isOperator(String ch) 
    {
        if(ch.equals("+") || ch.equals("-") || ch.equals("*") || ch.equals("/"))
            return true;
        return false;
    }

    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<>();

        for(int i=0;i<tokens.length;i++)
        {
            if(isOperator(tokens[i]))
            {
                int second = st.pop();
                int first = st.pop();
                int res;
                if(tokens[i].equals("+"))
                    res = first + second;
                else if(tokens[i].equals("-"))
                    res = first-second;
                else if(tokens[i].equals("*"))
                    res = first*second;
                else
                    res = first/second;
                st.push(res);
            }
            else
            {
                st.push(Integer.valueOf(tokens[i]));
            }
        }

        return st.peek();
    }
}