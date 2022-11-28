class Solution {
public:
    
    int appendCharacters(string s, string t) {
        
        int N = s.size();
        int M = t.size(); 
        
        int i=0,j=0;
        
        while(i < N && j < M) 
        {
            if(s[i] == t[j]) 
            {
                j++;
            }
            i++;
        }
        
        return M-j;
        
    }
};