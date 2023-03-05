class Solution {
public:
    
    int power(long x,long y)
    {
        int MOD = 1e9+7;
        
        long res = 1;
        while(y > 0) 
        {
            if(y%2 == 1) // if the power is odd then multiply by x.
            {
                res = (res%MOD*x%MOD)%MOD;
            }
            y = y/2;
            x = ((long)(x%MOD*x%MOD))%MOD;
        }
        res = res%MOD;
        
        return (int)res; 
    }
    
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
        
        return power(2,mergeSize);
        
    }
};