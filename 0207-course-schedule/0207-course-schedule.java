class Solution {

    public boolean isCycle(int currNode,boolean[] visited,boolean[] pathVisited,List<List<Integer>> adj) 
    {
        visited[currNode] = true;
        pathVisited[currNode] = true;
        for(int adjNode:adj.get(currNode)) 
        {
            if(!visited[adjNode]) 
                if(isCycle(adjNode,visited,pathVisited,adj))
                    return true;
            if(pathVisited[adjNode]) 
                return true;
        }

        pathVisited[currNode] = false;
        return false;
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // If there is cycle then it means there will be deadlock means 
        // we can't finish all the courses 
        boolean[] visited = new boolean[numCourses];
        boolean[] pathVisited = new boolean[numCourses];
        List<List<Integer>> adj = new ArrayList<>(); 

        for(int i = 0;i<numCourses;i++) 
        {
            adj.add(new ArrayList<>());
        }

        for(int i=0;i<prerequisites.length;i++) 
        {
            adj.get(prerequisites[i][1]).add(prerequisites[i][0]);
        }

        for(int i=0;i<numCourses;i++) 
        {
            if(!visited[i]) 
            {
                if(isCycle(i,visited,pathVisited,adj)) 
                    return false;
            }
        }

        return true;
    }
}