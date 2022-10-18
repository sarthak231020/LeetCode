class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        string bin = "";
        int temp = n;
        while(temp) 
        {
            bin = to_string(temp%2)+bin;
            temp = temp/2;
        }
        
        reverse(bin.begin(),bin.end()); 
        
        int p = 0;
        vector<int> powers;
        for(auto i:bin)
        {
            if(i == '1') 
                powers.push_back(pow(2,p));
            p++;
        }
        vector<int> ans;
        int MOD = 1000000007;
        for(int i=0;i<queries.size();i++) 
        {
            int left = queries[i][0];
            int right = queries[i][1];
            long long res = 1;
            for(int j=left;j<=right;j++) 
            {
                res = (((res%MOD) * (powers[j]%MOD))%MOD);
            }
            ans.push_back(res);
        }
        
        return ans;
        
        
    }
};