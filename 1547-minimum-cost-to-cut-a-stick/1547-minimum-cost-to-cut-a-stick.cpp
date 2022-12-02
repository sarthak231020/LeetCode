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
    //                                       A     B     C
            //for example if we multiplying 10*20 20*30 30*40 
            //                                 i  i         j
            // so we want A*B + B*C
            // 10 * 20 * 40 is required to added for final multiplication answer.
            // for matrices of size M*N N*O the number of multiplications req are 
            // -> M*N*O.
            mini = min(mini,steps);
        }

        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        
        int k = cuts.size();
        vector<vector<int>> dp(k,vector<int> (k,-1));
        return (int)solve(1,k-2,cuts,dp);
    }
};