class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int N = arr.size();
        vector<int> pse(N),nse(N);
        
        stack<int> st;
        for(int i=0;i<N;i++) 
        {
            while(!st.empty() && arr[st.top()] >= arr[i]) 
            {
                st.pop();
            }

            if(st.empty()) 
            {
                pse[i] = -1;
            }
            else
            {
                pse[i] = st.top();
            }
            st.push(i);
        }
        
        while(!st.empty())
        {
            st.pop();
        }
        for(int i=N-1;i>=0;i--) 
        {
            while(!st.empty() && arr[st.top()] > arr[i]) 
            {
                st.pop();
            }

            if(st.empty()) 
            {
                nse[i] = N;
            }
            else
            {
                nse[i] = st.top();
            }
            st.push(i);
        }
        int MOD = 1e9+7;
        long long ans = 0;
        for(int i=0;i<N;i++) 
        {
            int count = (((i-pse[i])*(nse[i]-i))%MOD);
            ans += (((long long)(count)*((long long)(arr[i])))%MOD);
            ans %= MOD;
        }
        
        return (int)(ans);
    }
};