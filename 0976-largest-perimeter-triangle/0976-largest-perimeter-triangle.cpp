class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int N = nums.size();
        for(int i=N-1;i>=2;i--) 
        {
            double s = (nums[i]+nums[i-1]+nums[i-2])/2.0;
            double area = sqrt(s*(s-nums[i])*(s-nums[i-1])*(s-nums[i-2]));
            // cout<<s<<" "<<area<<endl;
            if(area > 0.0)
            {
                return nums[i]+nums[i-1]+nums[i-2];   
            }
        }
        return 0;
    }
};