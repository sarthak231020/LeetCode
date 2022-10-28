
// int solve(int days,int last,vector<vector<int>> &points,vector<vector<int>> &dp) 
// {
//     if(days == 0) 
//     {
//         int maxi = 0;
//         for(int i=0;i<3;i++) 
//         {
//             if(i!=last) 
//             {
//                 maxi = max(maxi,points[days][i]);
//             }
//         }
//         return maxi;
//     }
//     if(dp[days][last] != -1) 
//         return dp[days][last];
    
//     int maxi = 0;
//     for(int i=0;i<3;i++) 
//     {
//         if(i != last)
//         {
//             int pointsEarned = points[days][i]+solve(days-1,i,points,dp);
//             maxi = max(maxi,pointsEarned);
//         }
//     }
//     return dp[days][last] = maxi;
// }
int ninjaTraining(int n, vector<vector<int>> &points)
{
//     vector<vector<int>> dp(n+1,vector<int> (4,-1));
//     //Pass 3 initially since we are allowed
//     return solve(points.size()-1,3,points,dp);
    // Write your code here.
    
//     vector<vector<int>> dp(n+1,vector<int> (4,-1));
    //Converting the Base Case.
    
//     dp[0][0] = max(points[0][1],points[0][2]);
//     dp[0][1] = max(points[0][0],points[0][2]);
//     dp[0][2] = max(points[0][0],points[0][1]);
//     dp[0][3] = max(points[0][0],max(points[0][1],points[0][2])); //In Case first one is the only way 
//     for(int days=1;days<n;days++) 
//     {
//         for(int last=0;last<4;last++)  
//         {   
//             dp[days][last] = 0;
//             for(int task=0;task<3;task++)
//             {
//                 if(last != task)
//                 {
//                     dp[days][last] = max(dp[days][last],points[i][task]+dp[i-1][task]);
//                 }
//             }
//         }
//     }
//     return dp[n-1][3];
    
    //Most Optimized Code :- 
    vector<int> prev(4,0);
    prev[0] = max(points[0][1],points[0][2]);
    prev[1] = max(points[0][0],points[0][2]);
    prev[2] = max(points[0][0],points[0][1]);
    prev[3] = max(points[0][0],max(points[0][1],points[0][2]));
    
    for(int days=1;days<n;days++)
    {
        vector<int> curr(4,0);
        for(int last=0;last<4;last++) 
        {
            curr[last] = 0;
            for(int task=0;task<3;task++) 
            {
                if(task != last) 
                {
                    curr[last] = max(curr[last],points[days][task]+prev[task]);
                }
            }
        }
        prev = curr;
    }
    
    return prev[3];
}
