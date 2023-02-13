//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> ans;
        vector<int> visited(V,0);
        
        queue<int> q; 
        q.push(0);
        visited[0] = 1; //marking the root node as visited.
        while(!q.empty())  // O(V) this will run Number vertices times in total.
        {
            int top = q.front(); 
            q.pop();
            ans.push_back(top); 
            for(auto i:adj[top]) //-> this will run for O(2*E) total no. of degree times.
            {
                if(visited[i] != 1)
                {
                    visited[i] = 1;
                    q.push(i);
                }
            }
            
        }
        return ans;
        
        // Code here
        // TC -> O(V) + O(2*E)
        // SC -> O(3*V) => O(V).
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends