class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int sum = 0;
        unordered_map<int,int> mp; // will carry the remainder and its occurances.
        mp[0] = 1;
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++) 
        {
            sum += nums[i];
            int rem = (sum%k);
            if(rem < 0) 
                rem += k;
            if(mp.find(rem) != mp.end()) 
                ans += mp[rem];
            mp[rem]++;
        }
        
        return ans;
    }
};