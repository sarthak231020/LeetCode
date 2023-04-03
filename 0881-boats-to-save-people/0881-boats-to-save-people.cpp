class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        
        int ans = 0;
        int count = 0;
        int j = people.size()-1;
        while(j>=0 && people[j] == limit) 
        {
            count += 1;
            j--;
            ans += 1;
        }
        int i=0;
        
        while(i < people.size() && j >= 0 && i <= j) 
        {
            if(people[i]+people[j] <= limit) 
            {
                i++;
                j--;
                count += 2;
                ans +=1;
            }
            else
            {
                j--;
                ans += 1;
            }
        }
        
        
        return ans;
        
    }
};