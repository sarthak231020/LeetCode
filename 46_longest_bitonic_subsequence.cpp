#include <bits/stdc++.h> 

int longestBitonicSequence(vector<int>& arr, int n) {
    vector<int> dp1(n,1),dp2(n,1);
    
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<i;j++) 
        {
            if(arr[i] > arr[j] && dp1[i] < dp1[j]+1)
            {
                dp1[i] = 1+dp1[j];
            }
            if(arr[n-i-1] > arr[n-j-1] && dp2[n-i-1] < dp2[n-j-1]+1)
            {
                dp2[n-i-1] = 1+dp2[n-j-1];
            }
        }
    }
    int maxi = 1;
    for(int i=0;i<n;i++) 
    {
        maxi = max(maxi,dp1[i]+dp2[i]-1);
    }
    return maxi;
	  // Write your code here.	   
} 
