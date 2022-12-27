class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> remaining;
        int N = capacity.size();
        for(int i=0;i<N;i++) 
        {
            remaining.push_back(capacity[i]-rocks[i]);
        }
        
        sort(remaining.begin(),remaining.end());
        // for(auto i:remaining) 
        //     cout<<i<<" "; 
        // cout<<endl;
        int cnt = 0;
        for(int i=0;i<N;i++) 
        {
            if(additionalRocks-remaining[i] < 0) 
                break;
            cnt++;
            additionalRocks -= remaining[i];
        }
        
        return cnt;
    }
};