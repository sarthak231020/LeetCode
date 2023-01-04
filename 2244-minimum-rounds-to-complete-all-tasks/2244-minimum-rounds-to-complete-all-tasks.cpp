class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        
        for(auto i:tasks)
        {
            mp[i]++;
        }
        int res = 0;
        
        for(auto i:mp) 
        {
            if(i.second == 1) 
                return -1;
            if(i.second%3 == 0) 
            {
                res += i.second/3;
            }
            if(i.second%3 == 1) 
            {
                res += (2)+(i.second/3-1);
            }
            if(i.second%3 == 2) 
            {
                res += 1+(i.second/3);
            }
        }
        
        return res;
    }
};