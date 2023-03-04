class Solution {
public:
    // Brutforce Solution TLE.
    long long brut(vector<int>& nums, int minK, int maxK)
    {
        long long res = 0;
        
        for(int i=0;i<nums.size();i++) 
        {
            int mini = INT_MAX,maxi = INT_MIN;
            for(int j=i;j<nums.size();j++) 
            {
                mini = min(mini,nums[j]);
                maxi = max(maxi,nums[j]);
                if(mini == minK && maxi == maxK) 
                    res++;
            }
        }
        
        return res;
    }
    
    long long optimized(vector<int> &nums,int minK,int maxK) 
    {
        long jbad=-1,jmin=-1,jmax=-1,res=0;
        
        for(int i=0;i<nums.size();i++) 
        {
            if(nums[i] < minK || nums[i] > maxK) 
                jbad = i;
            if(nums[i] == minK) 
                jmin = i;
            if(nums[i] == maxK) 
                jmax = i;
            res += max(0L,min(jmin,jmax)-jbad);
        }
        return res;
    }
    
    
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        // return brut(nums,minK,maxK);        // O(N^2) TLE...
        return optimized(nums,minK,maxK);
    }
};