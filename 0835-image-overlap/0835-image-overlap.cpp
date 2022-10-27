#include<bits/stdc++.h>

class Solution {
public:
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int N = img1.size();
        vector<int> flattenedOnes1,flattenedOnes2;
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++) 
            {
                if(img1[i][j] == 1) 
                {
                    flattenedOnes1.push_back(i*100+j);
                }
            }
        }
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++) 
            {
                if(img2[i][j] == 1) 
                {
                    flattenedOnes2.push_back(i*100+j);
                }
            }
        }
        
        unordered_map<int,int> matchingOnesCount;
        for(auto i:flattenedOnes1) 
        {
            for(auto j:flattenedOnes2)
                matchingOnesCount[i-j]++;
        }
        
        int maxi = 0;
        for(auto it:matchingOnesCount) 
            maxi = max(maxi,it.second);
        
        return maxi;
    }
};