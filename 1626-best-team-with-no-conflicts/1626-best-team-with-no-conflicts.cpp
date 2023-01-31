class Solution {
public:
    
    static bool comp(pair<int,int> p1,pair<int,int> p2) 
    {
        if(p1.second < p2.second) 
            return true; 
        if(p1.second == p2.second) 
            return p1.first <= p2.first; 
        return false;
    }
    
    
    
    int solve(int i,int prevInd,vector<pair<int,int>> &feat,vector<vector<int>> &dp)
    {
        if(i == feat.size()) 
            return 0;
        if(dp[prevInd+1][i] != -1)
            return dp[prevInd+1][i];
        
        // Picking that particular
        int pick = -1e9;
        if(prevInd == -1 || feat[i].second == feat[prevInd].second || feat[i].first >= feat[prevInd].first)
            pick = feat[i].first + solve(i+1,i,feat,dp);
        int notPick = 0 + solve(i+1,prevInd,feat,dp);
        
        return dp[prevInd+1][i] = max(pick,notPick);
    }
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        
        int n = scores.size();
        vector<pair<int,int>> feat(n);
        int maxScore = INT_MIN;
        int maxAge = INT_MIN;
        for(int i=0;i<n;i++) 
        {
            feat[i].first = scores[i];
            feat[i].second = ages[i];
            maxScore = max(maxScore,scores[i]);
            maxAge = max(maxAge,ages[i]);
        }
        
        sort(feat.begin(),feat.end(),comp);
        
        // cout<<"NEXT"<<endl;
        
        // for(int i=0;i<n;i++) 
        // {
        //     cout<<feat[i].first<<" "<<feat[i].second<<endl;
        // }
        vector<vector<int>> dp(n,vector<int> (n,-1));
        
        return solve(0,-1,feat,dp);
        
        
        
    }
};