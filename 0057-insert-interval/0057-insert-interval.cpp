class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> ans;
        
        if(intervals.size() == 0) 
        {
            ans.push_back(newInterval);
            return ans;
        }
        
        int start = intervals[0][0];
        int i = 0;
        for(i=0;i<intervals.size();i++) 
        {
            if(newInterval[0] <= intervals[i][0]) 
                break;
        }
        
        intervals.insert(intervals.begin()+i,newInterval);
        int ending = intervals[0][1];
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++) 
        { 
            if(ending >= intervals[i][0]) 
            {
                ans.back()[1] = max(ending,intervals[i][1]);  
                ending = ans.back()[1];
            }
            else 
            {
                ending = intervals[i][1];
                ans.push_back(intervals[i]);
            }
        }
        
        return ans;
    }
};