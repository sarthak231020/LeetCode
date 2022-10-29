class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>,vector<string>> mp; 
        for(auto str:words) 
        {
            vector<int> diffrence;
            for(int j=0;j<str.length()-1;j++) 
            {
                diffrence.push_back((str[j+1]-'a')-(str[j]-'a'));
            }
            mp[diffrence].push_back(str);
        }
        
        for(auto it:mp) 
        {
            if(it.second.size() == 1) 
                return it.second[0];
        }
        return "";
    }
};