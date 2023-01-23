class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1) 
            return 1;
        unordered_map<int,vector<int>> mp1;  // key is the person which trusted by vector<int> peoples.
        unordered_map<int,int> mp2; // key,value => key (person who trust) the other person.
        
        for(int i=0;i<trust.size();i++) 
        {
            mp1[trust[i][1]].push_back(trust[i][0]);
        }
        
        for(int i=0;i<trust.size();i++) 
        {
            mp2[trust[i][0]] = trust[i][1];
        }
        
        for(int i=1;i<=n;i++) 
        {
            if(mp1.find(i) != mp1.end() && mp1[i].size() == n-1 && mp2.find(i) == mp2.end())
                return i;
        }
        return -1;
        
    }
};