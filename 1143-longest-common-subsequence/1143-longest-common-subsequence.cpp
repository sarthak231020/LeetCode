class Solution {
public:
    int solve(int ind1,int ind2,string text1,string text2,vector<vector<int>> &dp)
    {
        if(ind1 == -1 || ind2 ==-1) 
        {
            return 0;
        
            // if(ind1==0) 
            // {
            //     while(ind2>=0) 
            //     {
            //         if(text2[ind2] == text1[ind1])
            //             return 1;
            //         ind2--;
            //     }
            //     return 0;
            // }
            // if(ind2==0) 
            // {
            //     while(ind1>=0) 
            //     {
            //         if(text2[ind2] == text1[ind1])
            //             return 1;
            //         ind1--;
            //     }
            //     return 0;
            // }
        }
        if(dp[ind1][ind2] != -1) 
            return dp[ind1][ind2];
        
        int match = INT_MIN,misMatch = INT_MIN;
        if(text1[ind1] == text2[ind2]) 
            match = 1+solve(ind1-1,ind2-1,text1,text2,dp);
        else 
        {
            misMatch = max(solve(ind1-1,ind2,text1,text2,dp),solve(ind1,ind2-1,text1,text2,dp));
        }
        
        return dp[ind1][ind2] = max(match,misMatch);
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(),n2= text2.size();
        // cout<<"NEXT"<<endl;
        /*
        vector<vector<int>> dp(text1.size()+1,vector<int> (text2.size()+1,-1));
        return solve(n1-1,n2-1,text1,text2,dp);
        */
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
        
        for(int ind1=1;ind1<=n1;ind1++) 
        {
            for(int ind2=1;ind2<=n2;ind2++) 
            {
                int match = INT_MIN,misMatch = INT_MIN;
                if(text1[ind1-1] == text2[ind2-1]) 
                {
                    match = 1+dp[ind1-1][ind2-1];
                }
                else 
                {
                    misMatch = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
                dp[ind1][ind2] = max(match,misMatch);
            }
        }
        
        
        return dp[n1][n2];
    }
};