#include <bits/stdc++.h> 

int solve(int i,int j,int n,vector<vector<int>>& triangle,vector<vector<int>> &dp) 
{
    if(i == n-1) 
    {
        return triangle[i][j];
    }
    if(dp[i][j] != -1) 
        return dp[i][j];
    int curr = triangle[i][j]+solve(i+1,j,n,triangle,dp);
    int nex = triangle[i][j]+solve(i+1,j+1,n,triangle,dp);
    
    return dp[i][j] = min(curr,nex);
  
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    /*
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    return solve(0,0,n,triangle,dp);
    */
    /*
    vector<vector<int>> dp(n+1,vector<int> (n+1,0));
    
    for(int i=0;i<n;i++) 
    {
        dp[n-1][i] = triangle[n-1][i];
    }
    
    for(int i=n-2;i>=0;i--) 
    {
        for(int j=i;j>=0;j--) 
        {
            int curr = triangle[i][j]+dp[i+1][j];
            int nex = triangle[i][j]+dp[i+1][j];
            dp[i][j] = min(curr,nex);
        }
    }
    
    return dp[0][0];
    */
    
    vector<int> nextRow(n,0);
    
    for(int i=0;i<n;i++) 
    {
        nextRow[i] = triangle[n-1][i];
    }
    
    for(int i=n-2;i>=0;i--) 
    {
        vector<int> currRow(n,0);
        for(int j=i;j>=0;j--) 
        {
            int down = triangle[i][j]+nextRow[j];
            int downDiagonal = triangle[i][j]+nextRow[j+1];
            currRow[j] = min(down,downDiagonal);
        }
        nextRow = currRow;
    }
      
    return nextRow[0];
	// Write your code here.
}
