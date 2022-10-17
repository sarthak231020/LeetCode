class Solution {
public:
    string longestPalindrome(string s) {
        
        int N = s.size();
        string res = "";
        int resLen;
        for(int i=0;i<N;i++) 
        {
            // for odd length strings
            int j = i,k = i;
            
            while(j>=0 && k < N && s[j] == s[k]) 
            {
                if(k-j+1 > resLen)
                {
                    res = s.substr(j,k-j+1);
                    resLen = k-j+1;
                }
                j--;
                k++;
            }
            
            //for even length string
            j = i,k = i+1;
                
            while(j>=0 && k < N && s[j] == s[k]) 
            {
                if(k-j+1 > resLen) 
                {
                    res = s.substr(j,k-j+1);
                    resLen = k-j+1;
                }
                j--; 
                k++;
            }
        }
        return res;
    }
};