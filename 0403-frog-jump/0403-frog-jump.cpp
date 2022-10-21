class Solution {
public:
    bool solve(int ind,int N,vector<int> &stones,int lastJump,vector<vector<int>> &dp) 
    {
        if(ind == 0)
            return true;
        bool flag = false;
        for(int j=0;j<ind;j++) 
        {
            int dist = stones[ind]-stones[j];
            if(dist < 0 || dist > N || !dp[j][dist]) continue;

            if(dist-1 >= 0)
                dp[ind][dist-1] = true;
            if(dist+1 <= N) 
                dp[ind][dist+1] = true;
            dp[ind][dist] = true;
            flag = true;
            if(solve(ind-1,N,stones,dist,dp)) 
                return dp[ind][lastJump] = true;
        }
        return dp[ind][lastJump] = flag;
    }
    
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) 
            return false;
        int N = stones.size();
        vector<vector<int>> dp(N+1,vector<int>(N+1,0));
        // return solve(1,stones.size(),stones,1,dp);
        dp[0][1] = true;
        // return solve(N-1,N,stones,N-1,dp);
// //         dp[0][1] = true;
        
// //         for()
        // dp[]
        for(int i=1;i<N;i++) 
        {
            for(int j=0;j<i;j++) 
            {
                int dist = stones[i]-stones[j]; 
                if(dist < 0 || dist > N || !dp[j][dist]) 
                    continue; 
                dp[i][dist] = 1; 
                if(dist-1 >= 0) 
                    dp[i][dist-1] = 1;
                if(dist+1 <= N) 
                    dp[i][dist+1] = 1;
                if(i == N-1) 
                    return true;
            }
        }
        return false;
        
    }
};