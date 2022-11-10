class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        stack<char> st;
        for(int i=0;i<s.size();i++) 
        {
            if(!st.empty() && st.top() == s[i]) 
            {
                ans.pop_back();
                st.pop();
                continue;
            }
            ans.push_back(s[i]);
            st.push(s[i]);
        }
        
        return ans;
        
    }
};