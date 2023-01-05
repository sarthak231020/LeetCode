class Solution {
public:

    
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> st;
        
        for(auto num:nums) 
        {
            int divisor = 2;
            int temp = num;
            while(temp > 1) 
            {
                if(temp%divisor == 0) 
                {
                    st.insert(divisor);
                    temp /= divisor;
                }
                else 
                {
                    divisor++;
                }
            }
        }
        
        return st.size();
        
    }
};