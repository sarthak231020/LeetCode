class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int N = nums.size();
//         map<int,int> mp;
//         for(int i=0;i<N;i++) 
//         {
//             mp[nums[i]]++;
//         }
        unordered_map<int,int> count;
        count[nums[N-1]-nums[N-2]] = 1;
        int res = 0;
        for(int b=N-3;b>=1;b--) 
        {
            for(int a=b-1;a>=0;a--)     
            {
                res += count[nums[a]+nums[b]];
            }    
            
            for(int x = N-1;x>b;x--) 
            {
                count[nums[x]-nums[b]]++;
            }
            
        }
        
        return res;
    }
};