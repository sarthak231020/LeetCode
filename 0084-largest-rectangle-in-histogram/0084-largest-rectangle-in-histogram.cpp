class Solution {
public:
    int solveBrut(vector<int> &heights)
    {
        int N = heights.size();
        //Brut Sol for every ele find left smaller and right smaller and multiply
        //Will give us TLE since O(N^2) (10^10) (greater than 1 sec).
        int ans = INT_MIN;
        for(int i=0;i<N;i++) 
        {
            int j=i,l=0;
            while(j>=0 && heights[j] >= heights[i])
            {
                l++;
                j--;
            }
            int r = 0;
            j = i;
            while(j < N && heights[j] >= heights[i]) 
            {
                r++;
                j++;
            }
            ans = max(ans,heights[i]*(l+r-1)); 
        }
        
        return ans;
    }
    
    int solveBetter(vector<int> &heights)
    {
        int N = heights.size(); 
        stack<int> st;
        vector<int> nse(N),pse(N);
        for(int i=0;i<N;i++) 
        {
            while(!st.empty() && heights[st.top()] >= heights[i]) 
            {
                st.pop();
            }
            if(st.empty())
                pse[i] = 0;
            else
                pse[i] = st.top()+1;
            st.push(i);
        }
        while(!st.empty())
            st.pop();
        for(int i=N-1;i>=0;i--) 
        {
            while(!st.empty() && heights[st.top()] >= heights[i]) 
            {
                st.pop();
            }
            if(st.empty())
                nse[i] = N-1;
            else
                nse[i] = st.top()-1;
            st.push(i);
        }
        
        for(auto i:pse)
            cout<<heights[i]<<" ";
        cout<<endl;
        for(auto i:nse)
            cout<<heights[i]<<" ";
        cout<<endl;
        int ans = INT_MIN;
        
        for(int i=0;i<N;i++) 
        {
            ans = max(ans,heights[i]*(nse[i]-pse[i]+1));
        }
        return ans;
        
    }
    
    int solveOpt(vector<int> &heights) 
    {
        stack<int> st;
        int N = heights.size();
        int maxArea = INT_MIN;
        for(int i=0;i<=N;i++) 
        {  
            while(!st.empty() && (i==N || heights[st.top()] >= heights[i]))
            {
                int ele = heights[st.top()]; 
                st.pop();
                int width;
                if(st.empty()) 
                    width = i; 
                else 
                    width = i-st.top()-1;
                maxArea = max(maxArea,ele*width);
            }
            st.push(i);   
        }
        
        return maxArea;
    }
    
    
    
    int largestRectangleArea(vector<int>& heights) {
        
        // return solveBetter(heights);
        
        return solveOpt(heights);
        
    }
};