class Solution {
public:
    int lengthOfLastWord(string s) {
        int N = s.size();
        
        int i = N-1;
        int cnt = 0;
        while(i>=0 && s[i] == ' ') 
            i--;
        while(i>=0 && s[i] != ' ')
        {
            i--;
            cnt++;
        }
        return cnt;
    }
};