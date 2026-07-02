class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        // Applying Floyd Warshall to get every node's distance from every node.


        int[][] adjMat = new int[n][n];
        for(int[] edge:edges) 
        {
            adjMat[edge[0]][edge[1]] = edge[2];
            adjMat[edge[1]][edge[0]] = edge[2];
        }


        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                if(i != j && adjMat[i][j] == 0) 
                {
                    adjMat[i][j] = (int)(1e8);
                }
            }
        }

        for(int via=0;via<n;via++) 
        {
            for(int i=0;i<n;i++) 
            {
                for(int j=0;j<n;j++) 
                {
                    adjMat[i][j] = Math.min(adjMat[i][j],adjMat[i][via] + adjMat[via][j]);
                }
            }
        }


        int ans = 0;
        int lastMinCnt = Integer.MAX_VALUE;
        for(int i=0;i<n;i++) 
        {
            int cnt = 0;
            for(int j=0;j<n;j++) 
            {
                if(i != j && adjMat[i][j] <= distanceThreshold) 
                    cnt++;
            }
            if(cnt <= lastMinCnt)
            {
                lastMinCnt = cnt;
                ans = i;
            } 
        }

        return ans;
    }
}