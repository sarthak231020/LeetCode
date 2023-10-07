class Solution {
public:
    
    int isPossible(vector<int> &nums,int mid) 
    {
        int curr = 1; 
        long long currSum = 0;
        int N = nums.size();
        for(int i=0;i<N;i++) 
        {
            if(currSum + nums[i] <= mid) 
                currSum += nums[i];
            else 
            {
                curr++;
                currSum = nums[i];
            }
        }
        
        return curr;
        
    }
    
    int splitArray(vector<int>& nums, int k) {
        int maxi = *max_element(nums.begin(),nums.end());
        int sum = 0;
        for(auto i:nums) 
            sum += i;
        
        int N = nums.size();
        if(k == N) 
            return maxi;
        if(k == 1)  
            return sum;
        
        // Bruteforce ... 
//         for(int mid=maxi;mid<=sum;mid++) 
//         {
//             int val = isPossible(nums,mid);
            
//             if(val == k)
//                 return mid;
//         }
//         return maxi;
        // since we are not able to find any possible value so it is possible that always in higher value number of partitions are lesser than k 
        // but in case of minimum value that is maxi it is capturing more elements keeping the partitions lesser than K 
        // but at last we have to return maxi since we will not be able to capture all elements without it so we are returning the smallest possible answer.
        
        
        // coding it by Binary Search 
        int low = maxi,high = sum;
        int ans = low; // since if we are unable to find any answer than answer is lowest possible value.
        while(low <= high) 
        {
            int mid = (low + high)/2;
            
            int val = isPossible(nums,mid); 
            if(val == k) 
            {// since we need smallest possible answer.
                ans = mid; 
                high = mid-1;
            }
            else if(val < k) 
                high = mid-1;
            else 
                low = mid+1;
        }
        
        return ans;
        
    }
};