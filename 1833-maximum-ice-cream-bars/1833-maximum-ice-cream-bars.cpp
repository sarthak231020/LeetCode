class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        
        int ans=0;
        while(ans<costs.size() && coins > 0) 
        {
            if(coins < costs[ans])
                break;
            coins -= costs[ans];
            ans++;
        }
        
        return ans;
    }
};