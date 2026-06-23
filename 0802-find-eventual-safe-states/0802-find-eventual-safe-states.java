class Solution {

    public boolean containsCycle(int currNode,boolean[] visited,boolean[] pathVisited,int[][] graph) 
    {
        visited[currNode] = true; 
        pathVisited[currNode] = true;

        for(int adjNode:graph[currNode]) 
        {
            if(!visited[adjNode]) 
                if(containsCycle(adjNode,visited,pathVisited,graph)) 
                    return true;
            if(pathVisited[adjNode]) 
                return true;
        }
        pathVisited[currNode] = false;
        return false;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        int V = graph.length;
        boolean[] visited = new boolean[V];
        boolean[] pathVisited = new boolean[V];
        List<Integer> ans = new ArrayList<>();
        for(int i=0;i<V;i++) 
        {
            if(!visited[i])
            {
                if(!containsCycle(i,visited,pathVisited,graph))
                    ans.add(i);
            }
            Arrays.fill(visited,false);
            Arrays.fill(pathVisited,false);
        }

        Collections.sort(ans);
        return ans;
    }
}