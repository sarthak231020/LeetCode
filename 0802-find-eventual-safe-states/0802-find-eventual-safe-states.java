class Solution {

    public boolean containsCycle(int currNode,boolean[] visited,boolean[] pathVisited,boolean[] safe,int[][] graph) 
    {
        visited[currNode] = true; 
        pathVisited[currNode] = true;
        safe[currNode] = false;
        for(int adjNode:graph[currNode]) 
        {
            if(!visited[adjNode]) 
                if(containsCycle(adjNode,visited,pathVisited,safe,graph)) 
                    return true;
            if(pathVisited[adjNode]) 
                return true;
        }
        safe[currNode] = true; 
        pathVisited[currNode] = false;
        return false;
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        int V = graph.length;
        boolean[] visited = new boolean[V];
        boolean[] pathVisited = new boolean[V];
        boolean[] safe = new boolean[V];
        List<Integer> ans = new ArrayList<>();

        // Brutforce.
        // for(int i=0;i<V;i++) 
        // {
        //     if(!visited[i])
        //     {
        //         if(!containsCycle(i,visited,pathVisited,graph))
        //             ans.add(i);
        //     }
        //     Arrays.fill(visited,false);
        //     Arrays.fill(pathVisited,false);
        // }

        // Optimal.
        for(int i=0;i<V;i++) 
        {
            if(!visited[i]) 
                containsCycle(i,visited,pathVisited,safe,graph);
        }

        for(int i=0;i<V;i++) 
        {
            if(safe[i]) 
                ans.add(i);
        }

        return ans;
    }
}