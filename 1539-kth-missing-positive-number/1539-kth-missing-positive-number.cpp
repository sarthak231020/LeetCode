class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        unordered_map<int,int> mp; 
        
        for(int i=0;i<arr.size();i++) 
        {
            mp[arr[i]] = i;
        }
        
        int i=1;
        
        while(k) 
        {
           if(mp.find(i) == mp.end()) // means not present in arr
           {
               k--;
           }
           i++;
        }
        return i-1;
    }
};