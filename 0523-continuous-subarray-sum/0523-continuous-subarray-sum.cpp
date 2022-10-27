class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int K) {
        unordered_map<int,int> mp; //maintaining remainder(prefix sum%K) and index values.
        int N = nums.size();
        mp[0] = -1;
        int sum = 0;
        for(int i=0;i<N;i++) 
        {
            sum += nums[i];
            
            if(mp.find(sum%K) != mp.end() && i-mp[sum%K] >= 2) //That remainder already exist means the sum from that index till here is multiple of K that's why we are getting the same remainder again & their index difference is more than two elements in subarray.
            {
                return true;
            }
            if(mp.find(sum%K) == mp.end())
                mp[sum%K] = i;
        }
        
        return false;
    }
};