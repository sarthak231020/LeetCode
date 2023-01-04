class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream ss(s);
        string word;
        vector<string> v;
        while(ss >> word) 
        {
            v.push_back(word);
        }
        for(auto i:v) 
        {
            cout<<i<<" ";
        }
        cout<<endl;
        unordered_map<char,string> mp;
        for(int i=0;i<pattern.size();i++) 
        {
            if(mp.find(pattern[i]) != mp.end()) 
            {
                if(mp[pattern[i]] != v[i]) 
                    return false;
            }
            else 
            {
                mp[pattern[i]] = v[i];
            }
        }
        
        unordered_map<string,char> mp2;
        
        for(int i=0;i<v.size();i++) 
        {
            if(mp2.find(v[i]) != mp2.end()) 
            {
                if(mp2[v[i]] != pattern[i]) 
                    return false;
            }
            else 
            {
                mp2[v[i]] = pattern[i];
            }
        }
        
        
        for(auto i:mp) 
        {
            if(i.first != mp2[i.second])
                return false;
        }
        
        
        return true;
    }
};