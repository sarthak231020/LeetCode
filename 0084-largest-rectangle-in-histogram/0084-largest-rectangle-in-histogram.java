class Solution {

    public int optimalSol(int[] nums) 
    {
        int n= nums.length;
        int[] pse = new int[n];
        int[] nse = new int[n];
        Deque<Integer> st = new ArrayDeque<>();


        for(int i=0;i<n;i++) 
        {
            while(!st.isEmpty() && nums[st.peek()] >= nums[i])
                st.pop();
            pse[i] = st.isEmpty() ? -1 : st.peek();
            st.push(i);
        }
        st.clear();
        for(int i=n-1;i>=0;i--) 
        {
            while(!st.isEmpty() && nums[st.peek()] >= nums[i])
                st.pop();
            nse[i] = st.isEmpty() ? n : st.peek();
            st.push(i);
        }


        int ans = Integer.MIN_VALUE;

        for(int i=0;i<n;i++) 
        {
            ans = Math.max(ans,nums[i] * (i-pse[i]+nse[i]-i-1));
        }

        return ans;
    }

    public int largestRectangleArea(int[] heights) {
        return optimalSol(heights);
    }
}