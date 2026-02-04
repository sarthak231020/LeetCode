class Solution {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<Pair> maxHeap = new PriorityQueue<Pair>((a,b) -> Long.compare(b.key,a.key));

        for(int i=0;i<points.length;i++) 
        {
            int x = points[i][0];
            int y = points[i][1];

            long dist = (x*x*1L) + (y*y*1L);

            maxHeap.add(new Pair(dist,new int[] {x,y}));

            if(maxHeap.size() > k) 
                maxHeap.poll();
        }

        int[][] ans = new int[k][2];
        int i = 0;
        while(!maxHeap.isEmpty())
        {
            ans[i++] = maxHeap.poll().value;
        }

        return ans;
    }

    static class Pair
    {
        long key;
        int[] value;

        Pair(long key, int[] val) 
        {
            this.key = key;
            this.value = val;
        }
    }
}