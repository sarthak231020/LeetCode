class Solution {

    public void reverse(int[] nums,int start,int end) 
    {
        while(start < end) 
        {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    public void optimal(int[] nums,int k) 
    {
        int n = nums.length;
        k = k%n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }
    public void brut(int[] nums,int k) 
    {
        int n = nums.length, j = 0;
        int[] temp = new int[k];
        k = k%n;
        
        for(int i=n-k;i<n;i++)
            temp[j++] = nums[i];
        int l = n-1;
        for(int i=n-k-1;i>=0;i--)
            nums[l--] = nums[i];
        
        for(int i=0;i<k;i++)
            nums[i] = temp[i];
    }

    public void rotate(int[] nums, int k) {
        // brut(nums,k);
        optimal(nums,k);
    }
}