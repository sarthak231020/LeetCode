#include<bits/stdc++.h>
class Solution {
public:
    long long totalCost(vector<int>& costs, int K, int candidates) {
        
        priority_queue<int,vector<int>,greater<int>> minh1;
        priority_queue<int,vector<int>,greater<int>> minh2;
        int i,j;
        int N = costs.size();
        for(i=0;i<min(N,candidates);i++) 
        {
            minh1.push(costs[i]);
        }
        // i--;
        int cnt = costs.size()-1;
        for(j=0;j<min(N,candidates);j++) 
        {
            if(cnt == i-1)
                break;
            minh2.push(costs[cnt--]);
        }
        // cnt++; 
        long long ans = 0;
        for(int q=0;q<K;q++) 
        {
            // cout<<ans<<endl;
            if(minh1.empty() && minh2.empty())
                break;
            if(minh1.empty())
            {
                ans += minh2.top();
                minh2.pop();
                if(cnt>=i) 
                {
                    minh2.push(costs[cnt]);
                    cnt--;
                }
            }
            else if(minh2.empty())
            {
                ans += minh1.top();
                minh1.pop();
                if(i <= cnt) 
                {
                    minh1.push(costs[i]);
                    i++;
                }
            }
            else
            {
                if(minh1.top() <= minh2.top()) 
                {
                    ans += minh1.top();
                    minh1.pop();
                    if(i <= cnt) 
                    {
                        minh1.push(costs[i]);
                        i++;
                    }
                }
                else 
                {
                    ans += minh2.top();
                    minh2.pop();
                    if(cnt>=i) 
                    {
                        minh2.push(costs[cnt]);
                        cnt--;
                    }
                }
            }
        }
        
        return ans;
    }
};