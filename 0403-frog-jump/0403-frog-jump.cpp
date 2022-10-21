class Solution {
public:
    bool solve(int ind,int N,vector<int> &stones,int lastJump,vector<vector<int>> &dp) 
    {
        if(ind >= N) 
            return false;
        if(ind == N-1)
            return true;
        // cout<<stones[ind]<<" "<<lastJump<<endl;
        if(dp[ind][lastJump] != -1) 
            return dp[ind][lastJump];
        
        bool flag = false;
        for(int i=lastJump-1;i<=lastJump+1;i++) 
        {
            int k = ind+1;
            while(k < N) 
            {
                if(stones[ind]+i == stones[k]) 
                {
                    if(solve(k,N,stones,i,dp))
                    {
                        flag = true;
                        return dp[ind][lastJump] = true;
                    }
                }
                k++;
            }
            if(flag == true)
            {
                break;
            }
        }
        
        return dp[ind][lastJump] = flag;
    }
    
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) 
            return false;
        int N = stones.size();
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        
        
        return solve(1,stones.size(),stones,1,dp);
    }
};