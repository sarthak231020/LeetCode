class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        // if(m == 0) 
        //     return nums2[0]; 
        // if(n == 0) 
        //     return nums1[0];
        // cout<<"RUNNING"<<endl;
        vector<int> merged;
        int i = 0,j = 0;
        while((i<m) && (j<n)) 
        {
            if(nums1[i] < nums2[j]) 
            {
                merged.push_back(nums1[i]);
                i++;
            }
            else 
            {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while(i < m) 
        {
            merged.push_back(nums1[i]);
            i++;
        }
        while(j < n) 
        {
            merged.push_back(nums2[j]);
            j++;
        }
        // cout<<"working"<<endl;
        if(merged.size() == 1) 
            return merged[0];
        if(merged.size() == 2) 
            return (merged[0]+merged[1])/(double)(2.0);
        // cout<<"Working"<<endl;
        int k = merged.size();
        if(k%2 == 0) 
            return (merged[k/2]+merged[(k/2)-1])/(double)(2.0);
        else
            return merged[k/2];
        return 0.0;
    }
};