class Solution {
public:
    
    int countWays(vector<vector<int>>& ranges) {
        sort(ranges.begin(),ranges.end());
        vector<vector<int>> ans;
        for(auto interval:ranges) 
        {
            if(ans.empty() || ans.back()[1] < interval[0])
                ans.push_back(interval); 
            else
                ans.back()[1] = max(ans.back()[1],interval[1]);
        }
        int MOD = 1e9+7;
        int res = 1;
        for(int i=0;i<ans.size();i++) 
        {
            res = (res*2)%MOD;
        }
        
        return res;
        
    }
};