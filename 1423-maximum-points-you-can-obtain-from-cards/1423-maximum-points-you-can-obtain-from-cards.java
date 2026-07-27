class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int begin = 0,sum = 0, end = cardPoints.length-1,ans=0;
        int n = cardPoints.length;

        for(begin=0;begin<k;begin++) 
        {
            sum += cardPoints[begin];
        }
        begin--;
        if(k == n) 
            return sum;
        ans = sum;
        while(begin >= 0) 
        {
            sum -= cardPoints[begin--];
            sum += cardPoints[end--];
            ans = Math.max(sum,ans);
        }

        return ans;
    }
}