class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
            
        // Brut Solution 
        
//         int N = arr.size();
//         if(N == 1) 
//             return arr[0];
//         if(arr[0] != arr[1]) 
//             return arr[0];
//         if(arr[N-1] != arr[N-2]) 
//             return arr[N-1];
        
        
//         for(int i=1;i<N-1;i++) 
//         {
//             if(arr[i] != arr[i-1] && arr[i] != arr[i+1]) 
//                 return arr[i];
//         }
        
//         return -1;
        
        int N = arr.size();
        
        if(N == 1) 
            return arr[0];
        
        int low = 0, high = arr.size()-1;
        
        if(arr[low] != arr[low+1])
            return arr[low];
        if(arr[high] != arr[high-1]) 
            return arr[high];
        low++;
        high--;
        
        
        while(low <= high) 
        {
            int mid = (low + high)/2;
            
            if(arr[mid-1] != arr[mid] && arr[mid+1] != arr[mid]) 
                return arr[mid];
            
            // If mid is even && its pair exist on the left side means (odd,even) it means single element lies in right side part.
            if(mid%2 == 0 && arr[mid-1] == arr[mid])
            {
                // (odd, even) pair answer lies in left side.
                high = mid-1;
            }
            else if(mid%2 == 0 && arr[mid] == arr[mid+1])
            {   // (even,odd) pair so single element lies in right side.
                low = mid+1;
            }
            else if(mid%2 == 1 && arr[mid-1] == arr[mid])
            {
                // (even,odd) pair 
                low = mid+1;
            }
            else
                high = mid-1;
        }
        
        return -1;
    }
};