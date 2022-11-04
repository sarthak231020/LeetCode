#include <bits/stdc++.h> 

int solve(int i,int j,int m,int n,vector<vector<int>> &matrix,vector<vector<int>> &dp)
{
    if(j == -1 || j == n) 
        return INT_MIN;
    if(i == m-1) 
        return matrix[i][j];
    if(dp[i][j] != -1) 
        return dp[i][j];
    
    int down = solve(i+1,j,m,n,matrix,dp);
    if(down != INT_MIN) 
        down += matrix[i][j];
    int downLeft = solve(i+1,j-1,m,n,matrix,dp);
    if(downLeft != INT_MIN) 
        downLeft += matrix[i][j];
    int downRight = solve(i+1,j+1,m,n,matrix,dp);
    if(downRight != INT_MIN) 
        downRight += matrix[i][j];
    int maxi = INT_MIN;
    maxi = max(down,max(downLeft,downRight));
    
    return dp[i][j] = maxi;
}

int getMaxPathSum(vector<vector<int>> &matrix)
{
    /* memoized Code TC -> O(m*n) SC -> O(m-1+ (m*n)). m-1 stack space 
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
    
    int maxi = INT_MIN;
    for(int j=0;j<n;j++) 
        maxi = max(maxi,solve(0,j,m,n,matrix,dp));
    return maxi;
    */
    
    /* Tabulation TC -> O(m*n) SC->O(m*n).
    int m = matrix.size();
    int n = matrix[0].size();
    
    vector<vector<int>> dp(m+1,vector<int> (n+1,-1));
    
    for(int j=0;j<n;j++) 
    {
        dp[m-1][j] = matrix[m-1][j];
    }
    
    for(int i=m-2;i>=0;i--) 
    {
        for(int j=0;j<n;j++) 
        {
            int down = dp[i+1][j] + matrix[i][j];
            int downLeft = INT_MIN;
            if(j-1 >= 0)
                downLeft = dp[i+1][j-1] + matrix[i][j];
            int downRight = INT_MIN;
            if(j+1 < n)
                downRight = dp[i+1][j+1] + matrix[i][j];
            int maxi = INT_MIN;
            maxi = max(down,max(downLeft,downRight));
            dp[i][j] = maxi;
        }
    }
    int maxi = INT_MIN;
    for(int j=0;j<n;j++) 
    {
        maxi = max(maxi,dp[0][j]);
    }
    return maxi;
    */
    
    //Space Optimized TC -> O(m*n) SC -> O(2*n).
    int m = matrix.size();
    int n = matrix[0].size();
    
    vector<int> nextRow(n,-1);
    
    for(int j=0;j<n;j++) 
    {
        nextRow[j] = matrix[m-1][j];
    }
    
    for(int i=m-2;i>=0;i--) 
    {
        vector<int> currRow(n,-1);
        for(int j=0;j<n;j++) 
        {
            int down = nextRow[j] + matrix[i][j];
            int downLeft = INT_MIN;
            if(j-1 >= 0)
                downLeft = nextRow[j-1] + matrix[i][j];
            int downRight = INT_MIN;
            if(j+1 < n)
                downRight = nextRow[j+1] + matrix[i][j];
            int maxi = INT_MIN;
            maxi = max(down,max(downLeft,downRight));
            currRow[j] = maxi;
        }
        nextRow = currRow;
    }
    int maxi = INT_MIN;
    for(int j=0;j<n;j++) 
    {
        maxi = max(maxi,nextRow[j]);
    }
    return maxi;
    //  Write your code here.
}
