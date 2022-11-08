class Solution {
public:
    string makeGood(string s) {
        string ans;
        int i;
        while(!s.empty()) 
        {
            ans = "";
            for(i=0;i<s.size()-1;i++) 
            {
                if((islower(s[i]) && s[i+1] == toupper(s[i])) || (isupper(s[i]) && s[i+1] == tolower(s[i])))
                {
                    i = i+1;
                }
                else 
                {
                    ans.push_back(s[i]);
                }
            }
            if(i != s.size()) 
            {
                ans.push_back(s[i]);
            }
            if(s == ans) 
                break;
            s = ans;
        }
        
        return ans; 
    }
};