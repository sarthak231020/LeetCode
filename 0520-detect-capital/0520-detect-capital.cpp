class Solution {
public:
    
    bool allCapitals(string &word) 
    {
        for(auto i:word) 
        {
            if(islower(i)) 
                return false; 
        }
        return true; 
    }
    
    bool allSmalls(string &word) 
    {
        for(auto i:word)
        {
            if(isupper(i))
                return false;
        }
        return true;
    }
    
    bool firstCapAndAllSmall(string &word) 
    {
        if(islower(word[0])) 
            return false;
        for(int i=1;i<word.size();i++) 
        {
            if(isupper(word[i]))
                return false;
        }
        return true;
    }
    
    
    bool detectCapitalUse(string word) {
        return (allCapitals(word) || allSmalls(word) || firstCapAndAllSmall(word));
        
    }
};