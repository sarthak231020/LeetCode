class Solution {
public:
    
    string helperCountAndSay(string s) 
    {
        // string ans = ""; 
        // char prev = '!';
        // int cnt = 1;
        // bool flag = true;
        // for(int i=0;i<s.size();i++) 
        // {
        //     if(prev == s[i]) 
        //     {
        //         cnt++;
        //         flag = false;
        //     }
        //     else 
        //     {
        //         ans += to_string(cnt);
        //         ans += s[i];
        //         prev = s[i];
        //         cnt = 1;
        //         flag = true;
        //     }
        // }
        // if(flag == false) 
        // {
        //     ans += to_string(cnt);
        //     ans += s[s.size()-1];
        // }
        // cout<<ans<<endl;
        // return ans;
        int N = s.size();
        string ans = "";
        for(int i=0;i<N;i++) 
        {
            int cnt = 1;
            int j = i;
            while(j<N-1 && s[j] == s[j+1]) 
            {
                cnt++;
                j++;
            }
            ans += to_string(cnt);
            ans += s[j];
            i = j;
        }
        return ans;
    }
    
    string countAndSay(int n) {
        if(n == 1) 
            return "1";
        string temp = countAndSay(n-1);
        
        return helperCountAndSay(temp);
    }
};