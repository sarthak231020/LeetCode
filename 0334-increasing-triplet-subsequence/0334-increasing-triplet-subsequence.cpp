class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX,c2 = INT_MAX;
        
        for(auto x:nums) 
        {
            if(x <= c1) // x is the candidate for 1st element 
                c1 = x; //store it in candidate 1
            else if(x <= c2) //x > than 1st element so can be 2nd or 3rd element 
                c2 = x; // store it in candidate 2
            else  //it means x is bigger than c1 and c2 so we have the triplet
                return true; 
        }
        return false;
    }
};