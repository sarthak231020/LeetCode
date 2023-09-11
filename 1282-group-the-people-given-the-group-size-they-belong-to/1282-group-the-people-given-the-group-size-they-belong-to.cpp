class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        map<int,vector<int>> mp;
        int ind = 0;
        for(auto i:groupSizes) 
        {
            mp[i].push_back(ind);
            ind++;
        }
        
        
//         for(auto i:mp) 
//         {
//             cout<<i.first<<endl;
//             for(auto j:i.second) 
//             {
//                 cout<<j<<" ";
//             }
//             cout<<endl;
//         }
        
        
        
        for(auto i:mp) 
        {
            int ptr = 0;
            for(int k=0;k<i.second.size()/i.first;k++)
            {
                vector<int> temp;
                for(int j=0;j<i.first;j++) 
                {
                    temp.push_back(mp[i.first][ptr++]);
                }
                ans.push_back(temp);
            } 
        }
        
        return ans;
    }
};