class Solution {
public:
    
    string minWindow(string s, string t) {
        int N = s.size();
        int M = t.size();
        if(N < M) 
            return "";
        
        unordered_map<char,int> mp; 
        // int cnt = 0;
        for(auto i:t) 
        {
            mp[i]++;
        }
        int cnt = mp.size(); //no of unique characters.
        
        int start = 0;
        int end = 0;
        string ans = "";
        int mini = INT_MAX;
        while(end < N) 
        {
            if(mp.find(s[end]) != mp.end()) 
            {
                mp[s[end]]--;
                if(mp[s[end]] == 0) 
                    cnt--;
            }
            while(start < end)
            {
                if(mp.find(s[start]) != mp.end()) 
                {
                    if(mp[s[start]] < 0) 
                        mp[s[start]]++;
                    else if(mp[s[start]] >= 0) 
                        break;
                }
                start++;
            }
            if(cnt == 0 && mini > end-start+1) 
            {
                mini = end-start+1;
                ans = s.substr(start,end-start+1);
                // cout<<ans<<" "<<mini<<endl;
            }
            
            end++;   
        }
        
        return ans;
    }
};