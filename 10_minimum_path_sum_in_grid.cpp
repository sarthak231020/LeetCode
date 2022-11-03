#include <bits/stdc++.h> 

int solve(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp) 
{
    if(i < 0 || j < 0) 
        return INT_MAX; 
    if(i == 0 && j == 0) 
        return grid[i][j];
    if(dp[i][j] != -1) 
        return dp[i][j];
//     int mini = INT_MAX;
    int up = solve(i-1,j,grid,dp);
    if(up != INT_MAX) 
        up += grid[i][j];
    int left = solve(i,j-1,grid,dp);
    if(left != INT_MAX) 
        left += grid[i][j]; //Observe here we are adding the value after completing the recusion call since rec call will give us min value and then we cache it dp if we do by passing a parameter to function dp will cache any bigger result and won't allow other recursion calls so make sure you are not using parameter for cost calculation in such problems.
    
//     return min(up,left);
    return dp[i][j] = min(up,left);
}

int minSumPath(vector<vector<int>> &grid) {
    /* FOR Memoized code TC-> O(M*N) SC-> O(number of states (m-1+n-1) + dp array (M*N) )
    int m = grid.size(); 
    int n = grid[0].size();
    vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
    return solve(m-1,n-1,grid,dp);
    */
    
    /* Tabulation TC -> same SC-> O(M*N) = DP Array 
    int m = grid.size(); 
    int n = grid[0].size();
    vector<vector<int>> dp(m,vector<int> (n,0));
    dp[0][0] = grid[0][0];
    
    for(int i=0;i<m;i++) 
    {
        for(int j=0;j<n;j++) 
        {
            if(i == 0 && j == 0) 
                dp[i][j] = grid[0][0];
            else 
            {
                int up = INT_MAX;
                int left = INT_MAX; 
                if(i > 0) 
                    up = dp[i-1][j]+grid[i][j];
                if(j > 0) 
                    left = dp[i][j-1]+grid[i][j];
                dp[i][j] = min(up,left);
            }
        }
    }
    return dp[m-1][n-1];
    */ 
    //Space Optimized Way TC->same SC-> 2*N
    int m = grid.size(); 
    int n = grid[0].size();
    vector<int> prevRow(n,0);
    prevRow[0] = grid[0][0];
    
    for(int i=0;i<m;i++) 
    {
        vector<int> currRow(n,0);
        for(int j=0;j<n;j++) 
        {
            if(i == 0 && j == 0) 
                currRow[j] = grid[0][0];
            else 
            {
                int up = INT_MAX;
                int left = INT_MAX; 
                if(i > 0) 
                    up = prevRow[j]+grid[i][j];
                if(j > 0) 
                    left = currRow[j-1]+grid[i][j];
                currRow[j] = min(up,left);
            }
        }
        prevRow = currRow;
    }
    return prevRow[n-1];
    
    // Write your code here.
}
