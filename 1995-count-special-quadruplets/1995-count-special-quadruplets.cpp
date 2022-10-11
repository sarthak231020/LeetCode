class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int N = nums.size();
//         map<int,int> mp;
//         for(int i=0;i<N;i++) 
//         {
//             mp[nums[i]]++;
//         }
        
        int cnt = 0;
        for(int i=0;i<N;i++) 
        {
            for(int j=i+1;j<N;j++) 
            {
                for(int k=j+1;k<N;k++) 
                {
                    int sum = nums[i]+nums[j]+nums[k];
                    for(int l = k+1;l<N;l++) 
                    {
                        if(sum == nums[l])
                            cnt++;
                    }
                }
            }
        }
        
        return cnt;
    }
};