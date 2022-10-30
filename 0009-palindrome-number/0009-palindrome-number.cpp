class Solution {
public:
    bool isPalindrome(int x) {
        
//         int cnt = 0;
//         int temp = x; 
//         while(temp) 
//         {
//             temp = temp/10; 
//             cnt++;
//         }
        
//         int i=0;
//         int N = cnt;
//         while(i<cnt/2) 
//         {
            
//             i++;
//         }
        
        string s = to_string(x);
        
        int N = s.size(); 
        int i = 0;
        while(i < N/2)
        {
            if(s[i] != s[N-i-1])
                return false;
            i++;
        }
        
        return true;
        
    }
};