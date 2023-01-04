class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,int> patternToInt;
        unordered_map<string,int> wordToInt;
        
        // cout<<patternToInt['a']<<endl; // if key doesn't exist it will return 0.
        istringstream ss(s);
        int i=0,n=pattern.size();
        
        for(string word;ss>>word;++i) 
        {
            // case 1 -> words are not expired but the pattern is expired so return false 
            //case 2 -> there is a mismatch 
            // consider this like example 2
            // a->1 dog -> 1 
            // b->2 cat -> 2
            // b ->3 cat-> 3 
            // a->1 fish-> 0 mismatch(breaks the rule of bijection) so return false.
            
            
            if(i == n || patternToInt[pattern[i]] != wordToInt[word])
            {
                return false;
            }
            
            patternToInt[pattern[i]] = wordToInt[word] = i+1;
        }
        
        return i == n;
    }
};