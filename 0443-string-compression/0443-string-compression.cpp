class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        for(auto i:chars) 
        {
            s += i;
        }
        
        cout<<s<<endl;
        
        if(s.size() == 1) 
            return 1;
        int cnt = 0; 
        char prev = '!';
        string path = "";
        bool flag = true;
        for(auto i:chars) 
        {
            if(i != prev) 
            {
                if(cnt > 1) 
                    path += to_string(cnt);
                path += i;
                cnt = 1;
                prev = i;
                flag = true;
            }
            else
            {
                cnt++;
                flag = false;
            }
        }
        if(flag == false) 
        {
            if(cnt > 1) 
                path += to_string(cnt);
        }
        
        cnt = 0;
        for(auto i:path) 
        {
            chars[cnt++] = i;
        }
        
        
        
        return path.size();
    }
};