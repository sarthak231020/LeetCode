#include<bits/stdc++.h>
class Solution {
public:
    long long totalCost(vector<int>& costs, int K, int candidates) {
        
        priority_queue<int,vector<int>,greater<int>> minh1;
        priority_queue<int,vector<int>,greater<int>> minh2;
        int i=0,j=costs.size()-1;
        long long ans = 0;
        for(int q=0;q<K;q++) 
        {
            while(minh1.size() < candidates && i <= j) 
                minh1.push(costs[i++]);
            while(minh2.size() < candidates && j >= i) 
                minh2.push(costs[j--]);
            
            int a = INT_MAX, b = INT_MAX;
            if(!minh1.empty()) 
            {
                a = minh1.top();
            }
            if(!minh2.empty())
            {
                b = minh2.top();
            }
            if(a <= b) 
            {
                ans += a; 
                minh1.pop();
            }
            else 
            {
                ans += b; 
                minh2.pop();
            }
        }
        
        return ans;
    }
};