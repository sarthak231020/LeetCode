class Pair
{
    int currVal, minVal;

    Pair(int currVal,int minVal) 
    {
        this.currVal = currVal;
        this.minVal = minVal;
    }
}

class MinStack {
    private Deque<Pair> st;
    
    public MinStack() {
        st = new ArrayDeque<>();
    }
    
    public void push(int val) {
        if(st.isEmpty()) 
        {
            st.push(new Pair(val,val));
        }
        else
        {
            st.push(new Pair(val,Math.min(st.peek().minVal,val)));
        }
    }
    
    public void pop() {
        if(st.isEmpty()) 
            return;
        st.pop();
    }
    
    public int top() {
        return st.peek().currVal;
    }
    
    public int getMin() {
        return st.peek().minVal;
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