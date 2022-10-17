class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = word1.size();
        int M = word2.size();
        vector<int> prev(M+1,0);
        vector<int> curr(M+1,0);
        for(int i=1;i<=N;i++) 
        {
            for(int j=1;j<=M;j++) 
            {
                if(word1[i-1] == word2[j-1]) 
                    curr[j] = 1+prev[j-1];
                else 
                    curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        int LCS = curr[M];
        
        return min(N,M)-LCS+max(N,M)-LCS;
    }
};