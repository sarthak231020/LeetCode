class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
//         map<string,map<string,int>> mp; 
        
//         int N = creators.size(); 
        
//         for(int i=0;i<N;i++) 
//         {
//             mp[creators[i]][ids[i]] = views[i];
//         }
        
//         string c="",i="";
//         vector<vector<string>> ans;
//         vector<pair<long long,pair<string,string>>> v;
//         long long res = INT_MIN;
        
//         for(auto it1:mp) 
//         {
//             cout<<it1.first<<" "<<it1.second->first<<" "<<it1.second->second<<endl;
//             long long v1 = 0;
//             int maxi = INT_MIN;
//             string s= ""; 
//             for(auto it2 : it1.second) 
//             {
//                 v1 += it2.second;
//                 if(it2.second > maxi) 
//                 {
//                     maxi = it2.second; 
//                     s = it2.first;
//                 }
//             }
//             if(v1 >= res)
//             {
//                 res = v1; 
//                 c = it1.first;
//                 i = s;
//                 v.push_back({v1,{c,i}});
//             }
//         }
        
//         sort(v.begin(),v.end());
//         // for(auto i:v) 
//         // {
//         //     cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
//         // }
//         int N1 = v.size();
//         int currViews = v[N1-1].first;
//         ans.push_back({v[N1-1].second.first,v[N1-1].second.second});
//         int j=N1-2;
//         while(j>=0 && currViews == v[j].first)
//         {
//             ans.push_back({v[j].second.first,v[j].second.second});
//             j--;
//         }
        
//         return ans;
        
        map<string,map<string,int>> mp;
        
        int N = creators.size();
        for(int i = 0;i<N;i++) 
        {
            mp[creators[i]][ids[i]] = views[i];
        }
        map<string,long long> mpTotViews; //store creator and their total views.
        long long maxi = INT_MIN;
        for(auto it:mp) 
        {
            long long views = 0;
            for(auto it1:it.second) 
            {
                views += it1.second;
            }
            mpTotViews[it.first] = views;
            maxi = max(maxi,views);
        }
        
        vector<string> topCreators;
        
        for(auto it:mpTotViews) 
        {
            if(it.second == maxi) 
            {
                topCreators.push_back(it.first);
            }
        }
        vector<vector<string>> ans;
        for(auto str:topCreators)
        {
            int vs = INT_MIN;
            string s = "";
            for(auto it:mp[str]) 
            {
                if(it.second > vs) 
                {
                    vs = it.second; 
                    s = it.first; 
                }
            }
            ans.push_back({str,s});
        }
        return ans;
    }
};