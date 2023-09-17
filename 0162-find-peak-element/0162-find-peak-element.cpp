class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int N = nums.size();
        
        
        if(N == 1) 
            return 0;
        
        // as problem says nums[-1] & nums[N] is -inf.
        if(nums[0] > nums[1]) 
            return 0;
        if(nums[N-1] > nums[N-2]) 
            return N-1;
        
        // Brut solution....
//         for(int i=1;i<N-1;i++) 
//         {
//             if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) 
//                 return i;
//         }
        
//         return -1;
        
        
        int low = 1,high = N-2;
        
        
        while(low <= high) 
        {
            int mid = (low+high)/2;
            
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) 
                return mid;
            if(nums[mid+1] > nums[mid]) 
                low = mid+1;
            else
                high = mid-1;
        }
        
        return -1;
    
    }
};