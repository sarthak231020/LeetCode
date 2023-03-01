class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
        priority_queue<int> pq;
        
        for(int i=0;i<nums.size();i++) 
        {
            pq.push(nums[i]);
        }
        
        int i=0;
        while(!pq.empty()) 
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};