class Solution {

    public int[] brutSol(int[] nums,int k) 
    {
        int n = nums.length;
        int[] output = new int[n-k+1];

        for(int i=0;i<=n-k;i++) 
        {
            int maxi = Integer.MIN_VALUE;
            for(int j=i;j<=i+k-1;j++)
            {
                maxi = Math.max(maxi,nums[j]);
            }  
            output[i] = maxi;
        }

        return output;
    }


    public int[] betterSol(int[] nums,int k) 
    {
        // TC --> O(NlogN) SC --> O(K)(Heap) + O(N-K+1)(Ans Array).

        PriorityQueue<int[]> maxHeap = new PriorityQueue<>((a,b) -> (b[0] - a[0]));
        int n = nums.length;
        int idx = 0;
        int[] output = new int[n-k+1];

        for(int i=0;i<n;i++)
        {
            maxHeap.offer(new int[] {nums[i],i});
            if(i >= k-1)
            {
                while(maxHeap.peek()[1] <= i-k)
                {
                    // keep popping the elements 
                    maxHeap.poll();
                }
                output[idx++] = maxHeap.peek()[0];
            }
        }

        return output;
    }

    public int[] optimalSol(int[] nums,int k) 
    {
        int n = nums.length;
        Deque<Integer> dq = new ArrayDeque<>();
        int[] output = new int[n-k+1];
        int l = 0, r = 0;

        while(r < n)
        {
            while(!dq.isEmpty() && nums[dq.getLast()] < nums[r])
            {
                dq.removeLast();
            }
            dq.addLast(r);

            if(l > dq.getFirst()) 
            {
                dq.removeFirst();
            }

            if((r+1) >= k) 
            {
              output[l] = nums[dq.getFirst()];
              l++;  
            }
            r++;
        }

        return output;
    }


    public int[] maxSlidingWindow(int[] nums, int k) {
        // return brutSol(nums,k);
        // return betterSol(nums,k);
        return optimalSol(nums,k);
    }
}