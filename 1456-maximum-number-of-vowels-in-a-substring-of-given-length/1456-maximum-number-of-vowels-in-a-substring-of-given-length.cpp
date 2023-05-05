class Solution {
public:
    
    bool isVowel(char c) 
    {
        return (c=='a' || c == 'e' || c=='i' || c == 'o' || c == 'u');
    }
    
    int maxVowels(string s, int k) {
        
        int cnt=0, ans=0, l=0, r=0, n=s.size();
        
        while(r < n) 
        {
            if(isVowel(s[r]))
                cnt++;
            if(r-l == k) 
            {
                if(isVowel(s[l])) 
                    cnt--;
                l++;
            }
            r++;
            ans = max(ans,cnt);
        }
        
        return ans;
    }
    
};