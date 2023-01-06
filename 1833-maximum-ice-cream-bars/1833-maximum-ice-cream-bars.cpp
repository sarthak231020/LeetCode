class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        
        int i=0;
        int ans = 0;
        while(i<costs.size() && coins > 0) 
        {
            if(coins < costs[i])
                break;
            coins -= costs[i];
            ans++;
            i++;
        }
        
        return ans;
    }
};