class Solution {
public:
    int difference(string q,string d) 
    {
        int cnt = 0;
        for(int i=0;i<q.size();i++) 
        {
            if(q[i] != d[i]) 
            {
                cnt++;
            }
        }
        
        return cnt;
    }
    
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for(auto q:queries) 
        {
            for(auto d:dictionary) 
            {
                if(difference(q,d) <= 2) 
                {
                    ans.push_back(q); 
                    break;
                }
            }
        }
        
        return ans;
    }
};