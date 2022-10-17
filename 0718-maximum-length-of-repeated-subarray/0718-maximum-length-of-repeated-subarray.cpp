class Solution {
public:
    
    
    int findLength(vector<int>& nums1, vector<int>& nums2)      {
        int N = nums1.size();
        int M = nums2.size();
        int res = INT_MIN;
        //Space Optimized Code :- 
        vector<int> prev(M+1,0);
        vector<int> curr(M+1,0);
        for(int i=1;i<=N;i++) 
        {
            for(int j=1;j<=M;j++) 
            {
                if(nums1[i-1] == nums2[j-1]) 
                {
                    curr[j] = 1+prev[j-1];
                    res = max(res,curr[j]);
                }
                else 
                    curr[j] = 0;
            }
            prev = curr;
        }
        if(res == INT_MIN) 
            return 0;
        return res;
    }
};