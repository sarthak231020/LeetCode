class Solution {
public:
    int solve(int i,int prevind,vector<int> &nums,vector<vector<int>> &dp) 
    {
        if(i == nums.size()) 
            return 0;
        if(dp[i][prevind+1] != -1) 
            return dp[i][prevind+1];
        // cout<<nums[i]<<" "<<prev<<endl;
        int take = 0;
        if(prevind == -1 || nums[i] > nums[prevind])
            take = 1+solve(i+1,i,nums,dp);
        int notTake = 0+solve(i+1,prevind,nums,dp);
        
        return dp[i][prevind+1] = max(take,notTake);
    }
    
    int solveTabulated(vector<int> &nums)
    {
        int N = nums.size(); 
        // -1 index for prevind is in 0
        // 0-> 1 , 1 -> 2  and so on.
        vector<vector<int>> dp(N+2,vector<int> (N+1,0));
        //No need to fill base case since it is returning the zeros.
        for(int i=N-1;i>=0;i--) 
        {
            for(int prevind=i-1;prevind>=-1;prevind--) 
            {
                // cout<<nums[i]<<" "<<prev<<endl;
                int take = 0;
                if(prevind == -1 || nums[i] > nums[prevind])
                    take = 1+dp[i+1][i+1];
                int notTake = 0+dp[i+1][prevind+1];
                
                dp[i][prevind+1] = max(take,notTake);
            }
        }
        return dp[0][0];
    }
    
    int solveTabulatedSpaceOpt(vector<int> &nums)
    {
        int N = nums.size(); 
        // -1 index for prevind is in 0
        // 0-> 1 , 1 -> 2  and so on.
        vector<int> next(N+1,0),curr(N+1,0);
        //No need to fill base case since it is returning the zeros.
        for(int i=N-1;i>=0;i--) 
        {
            for(int prevind=i-1;prevind>=-1;prevind--) 
            {
                // cout<<nums[i]<<" "<<prev<<endl;
                int take = 0;
                if(prevind == -1 || nums[i] > nums[prevind])
                    take = 1+next[i+1];
                int notTake = 0+next[prevind+1];
                
                curr[prevind+1] = max(take,notTake);
            }
            next = curr;
        }
        return next[0];
    }
    
    int solveOpt(vector<int> &nums) 
    {
        int N = nums.size();
        vector<int> dp(N,1);
        for(int i=0;i<N;i++) 
        {
            for(int j=0;j<i;j++) 
            {
                if(nums[j] < nums[i]) 
                {
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        int maxi = INT_MIN; 
        for(auto i:dp) 
        {
            maxi = max(maxi,i);
        }
        
        return maxi;
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        // cout<<"NEXT"<<endl;
        // vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1,-1));
        // return solve(0,-1,nums,dp);
        
        //tabulated :- TC :- O(N*N) SC:- O(N*N)
        // return solveTabulated(nums);
        
        //Space Optimizd TC :- O(N*N) SC:- O(2*N)
        // return solveTabulatedSpaceOpt(nums);
        
        return solveOpt(nums);
    }
};