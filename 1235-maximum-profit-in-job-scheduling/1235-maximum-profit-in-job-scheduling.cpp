class Job 
{
    public:
    int s,e,p;
    Job(int _s,int _e,int _p) 
    {
        s = _s;
        e = _e;
        p = _p;
    }
};



class Solution {
public:
    
    static bool comp(Job j1,Job j2) 
    {
        if(j1.e <= j2.e) 
            return true; 
        return false;
    }
    
    //TLE 
//     int solve(int ind,int t,vector<Job> &jobs,unordered_map<string,int> &dp) 
//     {
//         if(ind == jobs.size()) 
//         {
//             return 0;
//         }
//         if(dp.find(to_string(ind)+to_string(t))!=dp.end()) 
//             return dp[to_string(ind)+to_string(t)];
        
//         int take = 0;
//         if(jobs[ind].s >= t) 
//             take = jobs[ind].p+solve(ind+1,jobs[ind].e,jobs,dp);
//         int notTake = 0+solve(ind+1,t,jobs,dp);
        
//         return dp[to_string(ind)+to_string(t)] = max(take,notTake);
//     }
    //ABOVE SOLVE is TLE.
   
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int N = startTime.size(); 
        cout<<"NEXT"<<endl;
        vector<Job> jobs;
        int maxEndTime = INT_MIN;
        for(int i=0;i<N;i++) 
        {
            jobs.push_back(Job(startTime[i],endTime[i],profit[i]));
            maxEndTime = max(maxEndTime,endTime[i]);
        }
        sort(jobs.begin(),jobs.end(),comp);
        
//         for(int i=0;i<N;i++) 
//         {
//             cout<<jobs[i].s<<" "<<jobs[i].e<<" "<<jobs[i].p<<endl;
//         }
        
        //This is giving us a TLE.
        // unordered_map<string,int> dp;
        // return solve(0,0,jobs,dp);
        // return 0;
        
        map<int,int> mp; // it will hold the ending time and the max profit by this time.
        
        mp[0] = 0;
        for(auto j:jobs) 
        {
            int val = 0;
            val = j.p+(prev(mp.upper_bound(j.s))->second);
            
            if(val > mp.rbegin()->second) 
            {
                mp[j.e] = val;
            }
        }
        
        return mp.rbegin()->second;
    }
};