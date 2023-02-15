class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) {
        int N = nums.size()-1;
        vector<int> nums2;
        while(k) 
        {
            nums2.insert(nums2.begin(),k%10);
            k = k/10;
        }
        int M = nums2.size()-1;
        
        vector<int> ans;
        int carry = 0;
        while(N != -1 && M != -1) 
        {
            int res = (nums[N] + nums2[M] + carry);
            carry = res/10;
            ans.push_back(res%10);
            N--;
            M--;
        }
        while(N != -1) 
        {
            int res = (nums[N] + carry);
            carry = res/10;
            
            ans.push_back(res%10);
            N--;
        }
        while(M != -1) 
        {
            int res = (nums2[M] + carry);
            carry = res/10;
            ans.push_back(res%10);
            M--;
        }
        
        if(carry)
            ans.push_back(carry);
        
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};