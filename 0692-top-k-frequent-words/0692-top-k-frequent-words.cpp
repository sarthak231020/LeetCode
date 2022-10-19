class Solution {
public:
    
    static bool comp(pair<string,int> p1,pair<string,int> p2) 
    {
        if(p1.second > p2.second)  // if frequency of p1 is greater than remain in same order 
            return true;
        if(p1.second == p2.second) 
            return p1.first < p2.first;
        return false;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        unordered_map<string,int> mp1; 
        for(auto i:words) 
            mp1[i]++;
        
        vector<pair<string,int>> mp;
        for(auto i:mp1) 
        {
            mp.push_back(i);
        }
//         for(auto i:mp) 
//         {
//             cout<<i.first<<" "<<i.second<<endl;
//         }
        
        
        sort(mp.begin(),mp.end(),comp);
        // for(auto i:mp) 
        // {
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        
        int temp = 0;
        vector<string> ans;
        for(auto i:mp)
        {
            ans.push_back(i.first);
            temp++;
            if(temp == k) 
                break;
        }
        
        return ans;
        
    }
};