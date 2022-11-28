class Solution {
public:
    
    bool compare(string &s1,string &s2) 
    {
        int N = s1.size();
        int M = s2.size();
        if(N != M+1)  //Since we have already sorted the strings according to there lengths so it ensures that N>M
            return false;
        int first = 0, second = 0; //first -> s1, second -> s2
        while(first < N)  //We are moving first 
        {
            if(second < M && s1[first] == s2[second]) //if matches then move both 
            {
                first++;
                second++;
            }
            else 
            {
                first++;
            }
        }
        if(first == N && second == M) 
            return true;
        return false;
    }
    static bool comp(string &s1,string &s2) 
    {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int N = words.size();
        cout<<"NEXT"<<endl;
        
        sort(words.begin(),words.end(),comp); //Sorting size by size.
        vector<int> dp(N,1); //everyone in increasing subsequence by default.
        int maxi = 1;
        for(int i=0;i<N;i++) 
        {
            for(int j=0;j<i;j++) 
            {
                if((compare(words[i],words[j])) && dp[i] < dp[j]+1)
                {
                    dp[i] = dp[j]+1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};