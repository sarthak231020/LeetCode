class Solution {
public:
    
    void solve(int ind,int N,vector<int> &nums,vector<int> &path,vector<vector<int>> &ans) 
    {
        if(ind == N) 
        {
            ans.push_back(path); 
            return;
        }
        
        path.push_back(nums[ind]);
        solve(ind+1,N,nums,path,ans); //Include the element 
        path.pop_back();
        solve(ind+1,N,nums,path,ans); // do not include the element
    
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        
        solve(0,nums.size(),nums,path,ans);
        return ans;
    }
};