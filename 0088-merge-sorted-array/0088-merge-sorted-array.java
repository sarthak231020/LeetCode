class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        // Intuition of optimal code is begin from last valid indices and keep putting bigger element at last 
        // one edge case in some smaller elements remain in nums2 then just copy it in nums1 using last only.
        // Algo --
        // is just like move ptr's --> compare i and j if nums[j] is bigger or equal then put it to last and last-1 and j-1
        // else put nums[i] into last and move last-1 and i-1
        // then just check if something low values left in nums2 and put them using last ptr 
        // [2 3 5 0 0 0] -- [2 3 5 0 0 6] -- [2 3 5 0 5 6] -- [ 2 3 5 4 5 6] -- [2 3 3 4 5 6] -- [2 2 3 4 5 6] -- [1 2 2 3 4 5 6]
        // [1 4 6] 
        // [2 3 5 0 0 6]
        // [2 3 4 0 5 6]
        
        int last = m + n -1; 
        while(m > 0 && n > 0)
        {
            if(nums2[n-1] >= nums1[m-1])
            {
                nums1[last] = nums2[n-1];
                n--;
            }
            else
            {
                nums1[last] = nums1[m-1]; 
                m--;
            }
            last--;
        }

        while(n > 0) 
        {
            nums1[last--] = nums2[n-1];
            n--;
        }
        
    }
}