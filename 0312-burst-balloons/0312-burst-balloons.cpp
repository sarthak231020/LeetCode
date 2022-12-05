class Solution {
public:
    
    int solve(int i,int j,vector<int> &nums,vector<vector<int>> &dp) 
    {
        if(i > j) 
            return 0;
        if(dp[i][j] != -1) 
            return dp[i][j];
        
        int maxi = INT_MIN;
        for(int k=i;k<=j;k++) 
        {
            int ans = nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
            maxi = max(maxi,ans); 
        }
        return dp[i][j] = maxi;
    }
    
    int solveTabulated(vector<int> &nums,int N) 
    {
        vector<vector<int>> dp(N+1,vector<int> (N+1,0));
        
        for(int i=N;i>=1;i--) 
        {
            for(int j=i;j<=N;j++) 
            {
                int maxi = INT_MIN;
                for(int k=i;k<=j;k++) 
                {
                    int ans = nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums,dp)+solve(k+1,j,nums,dp);
                    maxi = max(maxi,ans);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][N];
    }
    
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        nums.push_back(1); //Just to avoid complication in calculations.
        nums.insert(nums.begin(),1); //Just to avoid complication in calculations.
        /*FOR MEMOIZED CODE -> TC:- O(N^3) SC:-O(N^2)(DP ARRAY)+O(N)(ASS).
        vector<vector<int>> dp(N+1,vector<int> (N+1,-1));
        return solve(1,N,nums,dp);
        */
        //Tabulated Code :- TC->O(N^3). SC->O(N^2)(DP ARRAY).
        return solveTabulated(nums,N);
        
    }
};