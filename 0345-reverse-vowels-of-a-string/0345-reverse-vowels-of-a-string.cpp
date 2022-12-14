class Solution {
public:
    bool isVowel(char c) 
    {
        c = tolower(c);
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c== 'u')
            return true; 
        return false;
        
    }
    string reverseVowels(string s) {
//         vector<int> v;
        
        // for(int i=0;i<s.size();i++) 
        // {
        //     if(isVowel(s[i])) 
        //         v.push_back(i);
        // }
        // for(auto i:v) 
        // {
        //     cout<<i<<" ";
        // }
        // cout<<endl;
//         int i=0,j=v.size()-1; 
//         while(i <= j) 
//         {
//             swap(s[v[i]],s[v[j]]); 
//             // cout<<s<<endl;
//             i++;
//             j--;
//         }
        
//         return s;
        
        int i=0,j = s.size()-1;
        while(i<=j) 
        {
            // cout<<s<<" "<<s[i]<<" "<<s[j]<<endl;
            if(isVowel(s[i]) && isVowel(s[j])) 
            {   
                // cout<<"IF"<<endl;
                swap(s[i],s[j]);
                i++; 
                j--;
            }
            else 
            {
                // cout<<"ELSE "<<s[i]<<" "<<s[j]<<endl;
                if(isVowel(s[i]) == false) //s[i] is consonant.
                    i++;
                if(isVowel(s[j]) == false) //s[j] is consonant.
                    j--;
            }
        }
        
        return s;
    }
};