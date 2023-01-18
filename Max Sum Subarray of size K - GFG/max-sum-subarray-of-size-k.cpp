//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int k, vector<int> &nums , int N){
        int n = nums.size();
        int i=0,j=0;
        long sum = 0,ans = INT_MIN;
        while(j < n) 
        {
            sum += nums[j];
            if(j-i+1 < k) 
                j++;
            else if(j-i+1 == k) 
            {
                ans = max(ans,sum); //Calculate the answer.
                //Sliding the window.
                sum -= nums[i]; // Remove the calculation for ith index.
                i++;
                j++;
            }
        }
        
        return ans;
        // code here 
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends