
class Solution {
public:
    
    static bool comp(pair<int,int> p1,pair<int,int> p2) 
    {
        if(p1.second > p2.second)
            return true;
        return false;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) 
    {
        int N = plantTime.size();
        if(N == 1)
            return plantTime[0]+growTime[0];
        vector<pair<int,int>> v;
        for(int i=0;i<N;i++) 
        {
            v.push_back({plantTime[i],growTime[i]});
        }
        
        sort(v.begin(),v.end(),comp);
        
        
//         for(auto i:v) 
//         {
//             cout<<i.first<<" "<<i.second<<endl;
//         }
//         cout<<endl;
        
//         int days = v[0].first;
        
//         for(int i=0;i<N-1;i++) 
//         {
//             days += (abs(v[i].second-v[i+1].first)+min(v[i].second,v[i+1].first)); 
//             cout<<days<<endl;
//         }
        
//         days += v[N-1].second;
//         days++;
        int curPlantTime =0;
        int days = 0;
        for(auto i:v)
        {
            curPlantTime += i.first;
            days = max(days,curPlantTime+i.second);
        }
    
        return days;
    }
};