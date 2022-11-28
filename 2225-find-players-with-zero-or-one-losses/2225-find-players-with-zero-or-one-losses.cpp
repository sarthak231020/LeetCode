class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        set<int> st;
        
        int N = matches.size();
        for(int i=0;i<N;i++) 
        {
            st.insert(matches[i][0]);
        }
        
        for(int i=0;i<N;i++) 
        {
            if(st.find(matches[i][1]) != st.end())
            {
                st.erase(matches[i][1]);
            }
        }
        vector<vector<int>> ans(2,vector<int>());
        for(auto i:st) 
        {
            ans[0].push_back(i);//Only Winners are extracted.
        }
        
        
        st.clear();
        map<int,int> mp;
        for(int i=0;i<N;i++) 
        {
            mp[matches[i][1]]++;
        }
        
        for(auto i:mp) 
        {
            if(i.second == 1)
                ans[1].push_back(i.first);
        }
        
        
        return ans;
        
        
    }
};