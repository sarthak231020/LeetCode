class Solution {
    public int lastStoneWeight(int[] stones) {
        if(stones.length == 1) 
            return stones[0];
        PriorityQueue<Integer> maxHeap = new PriorityQueue<>((a,b) -> b-a);
        for(int i=0;i<stones.length;i++)
        {
            maxHeap.add(stones[i]);
        }

        while(maxHeap.size() > 1) 
        {
            int first = maxHeap.poll();
            int second = maxHeap.poll();
            if(first == second) 
                continue;
            else
                maxHeap.add(first-second);
        }

        return maxHeap.isEmpty() ? 0 : maxHeap.poll();
    }
}