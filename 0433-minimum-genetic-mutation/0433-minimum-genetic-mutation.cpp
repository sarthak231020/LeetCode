class Solution {
public:
    
    int difference(string s,string e) 
    {
        int n = 8;
        int cnt = 0;
        for(int i=0;i<8;i++) 
        {
            if(s[i] != e[i]) 
                cnt++;
        }
        return cnt;
    }
    
    int solve(int steps,string start,string end,vector<int> visited, vector<string>& bank)
    {
        // cout<<start<<" "<<end<<endl;
        if(start == end) 
            return steps;
        
        int mini = INT_MAX;
        // bool flag = false;
        for(int i=0;i<bank.size();i++) 
        {
            if(bank[i] == start) 
                continue;
            if(difference(start,bank[i]) == 1 && visited[i] == -1) 
            {
                visited[i] = 1;
                mini = min(mini,solve(steps+1,bank[i],end,visited,bank));
            }
        }
        
        return mini;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        vector<int> visited(bank.size()+1,-1);
        int ans = solve(0,start,end,visited,bank);
        if(ans == INT_MAX) 
            return -1;
        return ans;
    }
};