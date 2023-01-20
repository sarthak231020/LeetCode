class Solution {
public:
    
    void solve(int i,vector<int> &nums,vector<int> &temp,set<vector<int>> &ans) 
    {
        if(i == nums.size()) 
        {
            if(temp.size() >= 2)
                ans.insert(temp);
            return;
        }
        
        bool flag = false;
        if(temp.empty()) 
        {
            flag = true;
            temp.push_back(nums[i]);
        }
        else if(nums[i] >= temp[temp.size()-1]) 
        {
            flag = true;
            temp.push_back(nums[i]);
        }
        solve(i+1,nums,temp,ans);
        if(flag) 
            temp.pop_back();
        solve(i+1,nums,temp,ans);
            
        
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> ans;
        
        solve(0,nums,temp,ans);
        
        vector<vector<int>> res(ans.begin(),ans.end());
        
        return res;
    }
};