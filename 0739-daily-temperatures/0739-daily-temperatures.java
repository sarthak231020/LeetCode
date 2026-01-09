class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> st = new Stack<>();
        int n = temperatures.length;
        int[] output = new int[n];

        for(int i=n-1;i>=0;i--) 
        {
            while(!st.isEmpty() && temperatures[st.peek()] <= temperatures[i])
            {
                st.pop();
            }
            output[i] = st.isEmpty() ? 0 : st.peek()-i;
            st.push(i);
        }

        return output;
    }
}