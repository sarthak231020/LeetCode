class Pair 
{
    int node,weight;
    Pair(int node,int weight) 
    {
        this.node = node;
        this.weight = weight;
    }
}

class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<Pair>> adjList = new ArrayList<>();
        for(int i=0;i<n+1;i++) 
            adjList.add(new ArrayList<>());
        for(int i=0;i<times.length;i++) 
            adjList.get(times[i][0]).add(new Pair(times[i][1],times[i][2]));

        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.add(new int[]{0,k});
        int[] dist = new int[n+1];
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[k] = 0;
        int ans = -1;
        while(!pq.isEmpty())
        {
            int[] current = pq.poll();
            int diff = current[0];
            int node = current[1];
            for(Pair p : adjList.get(node)) 
            {
                int adjNode = p.node; 
                int newDiff = diff + p.weight;
                if(newDiff < dist[adjNode]) 
                {
                    dist[adjNode] = newDiff;
                    pq.add(new int[]{newDiff,adjNode});
                }
            }
        }

        for(int i=1;i<=n;i++) 
        {
            if(dist[i] == Integer.MAX_VALUE)
                return -1;
            ans = Math.max(ans,dist[i]);
        }

        return ans;
    }
}