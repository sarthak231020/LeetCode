class Solution {
public:
    
    static bool comp(pair<char,int> p1,pair<char,int> p2)
    {
        return p1.second > p2.second;
    }
    
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        
        for(auto i:s) 
        {
            mp[i]++;
        }
        
        vector<pair<char,int>> v; 
        
        for(auto i:mp)
        {
            v.push_back({i.first,i.second});
        }
        
        
        sort(v.begin(),v.end(),comp);
        string ans = "";
        for(auto i:v) 
        {
            for(int j=0;j<i.second;j++) 
            {
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};