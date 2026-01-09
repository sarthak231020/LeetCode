class MinStack {
    Stack<Long> st;
    long mini;
    public MinStack() {
        st = new Stack<>();
    }
    
    public void push(int val) {
        if(st.isEmpty()) 
        {
            st.push(0L);
            mini = val;
        }
        else
        {
            st.push(val-mini);
            mini = Math.min(val,mini);
        }
    }
    
    public void pop() {
        if(st.isEmpty()) 
            return;
        long poppedEle = st.pop();
        // This means we popped the current minimum so update it....
        if(poppedEle < 0) 
            mini = mini - poppedEle;
    }
    
    public int top() {
        long top = st.peek();
        if(top > 0) 
        {
            return (int)(mini + top);
        }
        else
        {
            return (int)mini;
        }
    }
    
    public int getMin() {
        return (int)mini;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */