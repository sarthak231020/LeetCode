class Solution {
public:
    int countOrders(int n) {
        int slots = 2*n;
        long long result = 1;
        int MOD =  1e9+7;
        
        while(slots > 0) 
        {
            long long validOutcome = (slots*(slots-1))/2;
            result = (result%MOD * validOutcome%MOD)%MOD;
            slots -= 2;
        }
        
        return result%MOD;
    }
};