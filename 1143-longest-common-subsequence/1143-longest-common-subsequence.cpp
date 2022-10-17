class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        int N = text1.size();
        int M = text2.size();
//         vector<vector<int>> dp(N+1,vector<int>(M+1,-1));
        
//         for(int i=0;i<=N;i++) 
//         {
//             dp[i][0] = 0;
//         }
//         for(int j=0;j<=M;j++) 
//         {
//             dp[0][j] = 0;
//         }
        
        
//         for(int i=1;i<=N;i++) 
//         {
//             for(int j=1;j<=M;j++) 
//             {
//                 if(text1[i-1] == text2[j-1]) 
//                     dp[i][j] = 1+dp[i-1][j-1];
//                 else 
//                     dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//         return dp[N][M];
        
        //Space Optimized Code :- 
        vector<int> prev(M+1,0);
        vector<int> curr(M+1,0);
        for(int i=1;i<=N;i++) 
        {
            for(int j=1;j<=M;j++) 
            {
                if(text1[i-1] == text2[j-1]) 
                    curr[j] = 1+prev[j-1];
                else 
                    curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        return curr[M];
        
    }
};