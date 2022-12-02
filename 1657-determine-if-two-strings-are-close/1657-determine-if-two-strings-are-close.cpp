class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();
        
        if(n1 != n2) 
            return false;
        
        //Checking if they contains same chars and frequencies are interchangable.
        vector<int> freq1(26,0),freq2(26,0),uniq1(26,0),uniq2(26,0);
        
        for(auto c:word1) 
        {
            freq1[c-'a']++;
            uniq1[c-'a'] = 1; 
        }
        
        for(auto c:word2) 
        {
            freq2[c-'a']++;
            uniq2[c-'a'] = 1;
        }
        
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        
        if(freq1 == freq2 && uniq1 == uniq2) 
            return true;
        return false;
        
    }
};