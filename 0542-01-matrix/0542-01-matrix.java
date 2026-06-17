class Triplet
{
    int r,c,dist;

    Triplet(int r,int c,int dist) 
    {
        this.r = r;
        this.c = c;
        this.dist = dist;
    }
}
class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] ans = new int[m][n];
        
        Deque<Triplet> queue = new ArrayDeque<>();

        for(int i=0;i<m;i++) 
        {
            for(int j=0;j<n;j++) 
            {
                if(mat[i][j] == 0) 
                {
                    queue.offer(new Triplet(i,j,0));
                    ans[i][j] = 0;
                }
                else
                {
                    ans[i][j] = Integer.MAX_VALUE;
                }
            }
        }

        int[] dirx = {-1,0,1,0};
        int[] diry = {0,1,0,-1};

        while(!queue.isEmpty())
        {
            Triplet triplet = queue.poll();
            int r = triplet.r;
            int c = triplet.c;
            int dist = triplet.dist;
            for(int i=0;i<4;i++) 
            {
                int currR = r+dirx[i];
                int currC = c+diry[i];
                if(currR < 0 || currR >= m || currC < 0 || currC >= n || ans[currR][currC] != Integer.MAX_VALUE)
                {
                    continue;
                }
                ans[currR][currC] = dist+1;
                queue.offer(new Triplet(currR,currC,dist+1));
            }
        }

        return ans;
    }
}