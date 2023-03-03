class Solution {
public:
    int strStr(string haystack, string needle) {
        int N = haystack.size();
        int M = needle.size();
        int j = 0;
        int startInd = -1;
        int i = 0;
        for(i=0;i<N;i++) 
        {
            j = 0;
            if(haystack[i] == needle[j]) 
            {
                int k = i;
                while(k<N && j<M && haystack[k] == needle[j]) 
                {
                    k++;
                    j++;
                }
                if(j == M) 
                    return i;
            }
        }
        return -1;
    }
};