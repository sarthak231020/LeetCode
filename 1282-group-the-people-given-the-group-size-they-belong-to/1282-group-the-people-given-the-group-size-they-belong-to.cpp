class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // vector<vector<int>> ans;
        // map<int,vector<int>> mp;
        // int ind = 0;
        // Brut Solution.
        //      for(auto i:groupSizes) 
        //         {
        //             mp[i].push_back(ind);
        //             ind++;
        //         }
        
        // for(auto i:mp) 
        // {
        //     int ptr = 0;
        //     for(int j=0;j<i.second.size()/i.first;j++)
        //     {
        //         vector<int> temp;
        //         for(int k=0;k<i.first;k++) 
        //         {
        //             temp.push_back(mp[i.first][ptr++]);
        //         }
        //         ans.push_back(temp);
        //     }
        // }
        
        // Optimized.
        vector<vector<int>> ans;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<groupSizes.size();i++) 
        {
            int key = groupSizes[i]; // the group size is the key.
            
            if(mp[key].size() < key) 
            {
                mp[key].push_back(i);
            }
            if(mp[key].size() == key)
            {
                ans.push_back(mp[key]);
                mp.erase(key);
            }
            
        }
        
        return ans;
    }
};