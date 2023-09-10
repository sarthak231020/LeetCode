//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
	
	void printTriangle(int n) {
	    // code here
	    
	    for(int i=n-1;i>=0;i--) 
	    {
	        for(int j=1;j<=n*2-1;j++) 
	        {
	            if(j >= n-i && j <= n+i)
	            {
	                cout<<"*";
	            }
	            else if(j< n-i)
	            {
	                cout<<" ";
	            }
	        }
	        cout<<endl;
	    }
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        Solution ob;
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends