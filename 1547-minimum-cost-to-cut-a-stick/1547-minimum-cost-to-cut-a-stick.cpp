class Solution {
public:
    
    long long solve(int i,int j,vector<int> &arr,vector<vector<int>> &dp) 
    {
        if(i > j) 
        {
            return 0; //Since we are are processing only one ele only one dim of matrices.
        }
        if(dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;
        for(int k = i;k<=j;k++)
        {
            int steps = (arr[j+1]-arr[i-1])
                        + solve(i,k-1,arr,dp)
                        + solve(k+1,j,arr,dp);
            mini = min(mini,steps);
        }

        return dp[i][j] = mini;
    }
    
    
    int solveTabulated(vector<int> &arr,int N) 
    {
        vector<vector<int>> dp(N+1,vector<int> (N+1,0));
        for(int i=N-1;i>=1;i--) 
        {
            for(int j=i;j<N-1;j++)
            {
                int mini = INT_MAX;
                for(int k = i;k<=j;k++)
                {
                    int steps = (arr[j+1]-arr[i-1])
                                + dp[i][k-1]
                                + dp[k+1][j];
                    mini = min(mini,steps);
                }

                dp[i][j] = mini;

            }
        }
        
        return dp[1][N-2];
    }
    
    
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int k = cuts.size();
        
        //Memoized Code :- TC-> O(N^3) SC-> O(N^2)(DP ARRAY)+O(N)(ASS).
//         vector<vector<int>> dp(k,vector<int> (k,-1));
//         return (int)solve(1,k-2,cuts,dp);
        
        //Tabulated Code :- TC-> O(N^3) SC->O(N^2)(DP ARRAY).
        return solveTabulated(cuts,k);
        
        
    }
};