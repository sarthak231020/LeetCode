class Solution {
public:
    int search(vector<int>& arr, int target) {
        int N = arr.size();
        int low = 0,high = N-1;
        
        while(low <= high) 
        {
            int mid = (low+high)/2;
            
            if(arr[mid] == target) 
                return mid; 
            if(arr[low] <= arr[mid]) // this part is sorted
            {
                if(arr[low] <= target && target <= arr[mid]) 
                {
                    high = mid-1; //keep searching on left side.
                }
                else 
                    low = mid+1;
            }
            else 
            {
                if(arr[mid] <= target && target <= arr[high]) 
                {
                    low = mid+1; //keep searching on right side.
                }
                else 
                    high = mid-1;
            }
        }
        
        return -1;
    }
};