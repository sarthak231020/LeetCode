class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        
        // cout<<"START"<<endl;
        unordered_map<string,int> mp; //Store the string and its occurances 
        
        for(auto s:words) 
        {
            mp[s]++;
        }
        
        // for(auto it:mp) 
        // {
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        
        int cnt = 0;
        bool flag = false;
        for(auto it:mp) 
        {
            string s = it.first;
            // cout<<s<<" "<<cnt<<endl;
            if(s[0] == s[1])
            {
                // cout<<s<<" "<<cnt<<endl;
                if((mp[s]%2 == 1) && (flag == false))
                {//it is occuring odd times 
                    cnt += 2;
                    flag = true; //This means we have placed something in middle 
                    mp[s]--;
                }
                cnt += (4*(mp[s]/2));
            }
            else 
            {
                string r;
                r.push_back(s[1]);
                r.push_back(s[0]);
                // cout<<"RUNNING -> "<<s<<" "<<r<<" "<<cnt<<endl;
                if((mp[s] != 0)&& (mp.find(r) != mp.end())) 
                {
                    cnt += ((min(mp[s],mp[r])*4));
                    mp[s] = 0;
                    mp[r] = 0;
    
                }
            }
        }
        
        return cnt;
        
    }
};