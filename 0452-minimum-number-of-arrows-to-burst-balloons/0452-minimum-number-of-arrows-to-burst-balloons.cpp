class Solution {
public:
    static bool comp(vector<int> &v1,vector<int> &v2) 
    {
        if(v1[1] < v2[1])
            return true; 
        if(v1[1] == v2[1]) 
            return v1[0] <= v2[0];
        return false;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),comp);
        int shot = points[0][1];
        int ans = 1;
        // cout<<"NEXT"; 
        // for(auto i:points) 
        // {
        //     for(auto j:i)
        //         cout<<j<<" ";
        //     cout<<endl;
        // }
        
        for(int i=1;i<points.size();i++) 
        {
            if(shot < points[i][0])
            {
                ans++;
                shot = points[i][1];
            }
        }
        
        return ans;
        
    }
};