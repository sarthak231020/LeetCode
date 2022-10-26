class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0,sum=0;
        unordered_map<int,int> mp; // to hold prefix sum and their counts.
        
        mp[0] = 1; // for inclusion of subarrays which starts from begining or sum-k becomes 0.
        
        for(int i=0;i<nums.size();i++) 
        {
            sum += nums[i];
            if(mp.find(sum-k) != mp.end()) //if we are able to find sum-k in map it means we have k to become sum  
                ans += mp[sum-k];
            mp[sum]++;
        }
        
        return ans;
    }
};