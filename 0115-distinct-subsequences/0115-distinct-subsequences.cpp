class Solution {
public:
    int MOD = 1e9+7;
    int solve(int ind1,int ind2,string &s1,string &s2,vector<vector<int>> &dp)
    {
        if(ind2 == 0) 
            return 1; //that we have found the entire S in text
        if(ind1 == 0) 
            return 0; //we have reached to end of the text and not able to find S.

        if(dp[ind1][ind2] != -1) 
            return dp[ind1][ind2];
        if(s1[ind1-1] == s2[ind2-1]) 
            return dp[ind1][ind2] = (solve(ind1-1,ind2-1,s1,s2,dp)%MOD + solve(ind1-1,ind2,s1,s2,dp)%MOD )%MOD;
        else
            return dp[ind1][ind2] = solve(ind1-1,ind2,s1,s2,dp)%MOD;
    }
    
    int numDistinct(string s, string t) {
        int n1 = s.size(),n2 = t.size();
        vector<vector<int>> dp(n1+1,vector<int> (n2+1,-1));
        return solve(n1,n2,s,t,dp);
    }
};