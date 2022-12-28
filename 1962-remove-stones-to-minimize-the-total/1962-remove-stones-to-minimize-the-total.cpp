class Solution {
public:
    
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq; //max heap 
        int N = piles.size();
        for(int i=0;i<N;i++) 
        {
            pq.push(piles[i]);
        }
        
        // printPq(pq);
        
        // k--;
        while(k) 
        {
            // printPq(pq);
            int maxi = pq.top();
            pq.pop();
            maxi = maxi - maxi/2;
            if(maxi > 0)
                pq.push(maxi);
            if(pq.empty()) 
                break;
            k--;
        }
        int ans = 0;
        while(!pq.empty())
        {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};