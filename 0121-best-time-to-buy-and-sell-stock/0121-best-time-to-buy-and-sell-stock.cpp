class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = INT_MIN;
        int localMin = INT_MAX;
        
        for(int i=0;i<prices.size();i++) 
        {
            localMin = min(localMin,prices[i]);
            maxi = max(maxi,prices[i]-localMin);
        }
        
        return maxi;
    }
};