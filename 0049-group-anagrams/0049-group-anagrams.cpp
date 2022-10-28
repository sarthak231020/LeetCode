class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
    
        // unordered_
//         map<map<char,int>,vector<string>> mp;
        
//         for(auto i:strs) 
//         {
//             map<char,int> freqChars;
//             for(auto j:i) 
//             {
//                 freqChars[j]++;
//             }
//             mp[freqChars].push_back(i);
//         }
        
//         for(auto i:mp) 
//         {
//             ans.push_back(i.second);
//         }
        
//         return ans;
        
        map<vector<int>,vector<string>> mp;
        for(auto str:strs) 
        {
            vector<int> count(26,0);
            for(auto chars:str) // get the frequency of characters 
            {
                count[chars-'a']++;
            }
            mp[count].push_back(str); //store the string which have same frequencies of characters.
        }
        
        for(auto i:mp) 
        {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};