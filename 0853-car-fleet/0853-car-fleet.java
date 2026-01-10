class Solution {

    public int optimalSol(int target,int[] position,int[] speed) 
    {
        int n = position.length;
        int[][] pair = new int[n][2];

        for(int i=0;i<n;i++) 
        {
            pair[i][0] = position[i];
            pair[i][1] = speed[i];
        }

        Arrays.sort(pair,(a,b) -> Integer.compare(b[0],a[0])); 
        // Sort on the basis of their position in descending order..

        // Approach is that if someone taking longer time to reach the destination eventually merge with those who are taking lesser time.
        double prevTime = (target-pair[0][0])/(pair[0][1]*1.0);
        double currTime;
        int fleet = 1;
        for(int i=1;i<n;i++) 
        {
            currTime = (target-pair[i][0])/(pair[i][1]*1.0);
            if(currTime > prevTime)
            {
                fleet++;
                prevTime = currTime;
            }
        }

        return fleet;
    }

    public int carFleet(int target, int[] position, int[] speed) {
        
        return optimalSol(target,position,speed);

        // int n = position.length;
        // int[][] ps = new int[n][2];

        // for(int i=0;i<n;i++) 
        // {
        //     ps[i][0] = position[i];
        //     ps[i][1] = speed[i];
        // }

        // Arrays.sort(ps,(a,b) -> Integer.compare(b[0],a[0]));

        // for(int[] arr:ps) 
        // {
        //     System.out.println(arr[0] + " " + arr[1]);
        // }

        // Deque<Double> st = new ArrayDeque<>();

        // for(int i=0;i<n;i++)
        // {
        //     double timeToReach = (target-ps[i][0])/(ps[i][1]*1.0);
        //     if(st.isEmpty())
        //     {
        //         st.push(timeToReach);
        //     }
        //     else
        //     {
        //         if(st.peek() > timeToReach)
        //         {
        //             st.push(timeToReach);
        //         }
        //     }
        // }

        // return st.size();
    }
}