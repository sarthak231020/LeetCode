class Solution {
public:
    
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(),ranges.end());
        // vector<vector<int>> ans;
        int temp = INT_MIN;
        int mergeSize = 0;
        for(auto interval:ranges) 
        {
            if(temp == INT_MIN || temp < interval[0])
            {
                mergeSize++;
                temp = interval[1];
            }
            else
            {
                temp = max(temp,interval[1]);
            }
        }
        int MOD = 1e9+7;
        int res = 1;
        for(int i=0;i<mergeSize;i++) 
        {
            res = (res*2)%MOD;
        }
        
        return res;
        
    }
};