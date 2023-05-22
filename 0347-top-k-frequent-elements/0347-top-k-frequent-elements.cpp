class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        map<int,int> mp; 
        
        for(auto i:nums) 
        {
            mp[i]++;
        }
        
        for(auto i:mp) 
        {
            pq.push({i.second,i.first});
        }
        
        vector<int> ans;
        while(pq.size() > k) 
        {
            pq.pop();
        }
        
        while(!pq.empty()) 
        {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
            if(k == 0) 
                break;
        }
        
        return ans;
    }
};