class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) 
        {
            string ans = s;
            for(int i=1;i<s.size();i++) 
            {
                string temp = s.substr(i)+s.substr(0,i);
                if(temp < ans) 
                {
                    ans = temp;
                }
            }
            return ans;
        }       
        else
        {//In case of k >= 2 we are able to generate every permutation of string so we are able to generate the lexicographically smallest string 
            sort(s.begin(),s.end()); 
            return s;
        }
    }
};