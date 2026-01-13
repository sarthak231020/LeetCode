class Solution {

    public boolean ableToFinishAll(int[] piles,long speed,int h) 
    {
        long ans = 0;
        for(int i:piles) 
        {
            ans += Math.ceil(i/(speed*1.0));
        }
        return ans <= h;
    }

    public int minEatingSpeed(int[] piles, int h) {
        int n = piles.length;
        int sum = 0;
        long low = 1,high = 0, ans = Integer.MAX_VALUE;

        for(int i:piles) 
        {
            sum += i;
            high = Math.max(high,i);
        }

        while(low <= high)
        {
            long mid = low + (high-low)/2;
            if(ableToFinishAll(piles,mid,h))
            {
                ans = Math.min(ans,mid);
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }

        return (int)ans;
    }
}