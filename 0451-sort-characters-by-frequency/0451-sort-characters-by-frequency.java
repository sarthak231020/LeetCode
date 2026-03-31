class Solution {
    class Pair
    {
        char ch;
        int freq;
        Pair(char ch,int freq) 
        {
            this.ch = ch;
            this.freq = freq;
        }
    }
    public String usingMaxHeap(String s) 
    {
        Map<Character,Integer> freqMap = new HashMap<>();
        for(int i=0;i<s.length();i++)
        {
            freqMap.put(s.charAt(i),freqMap.getOrDefault(s.charAt(i),0)+1);
        }
        PriorityQueue<Pair> pq = new PriorityQueue<>((a,b) -> (b.freq-a.freq));
        freqMap.forEach((k,v) -> { 
            pq.add(new Pair(k,v));
        });
        StringBuilder ans = new StringBuilder();
        while(!pq.isEmpty())
        {
            Pair pair = pq.poll();
            for(int i=0;i<pair.freq;i++)
                ans.append(pair.ch);
            // freq.pop();
        }
        return ans.toString();
    }
    public String usingBucketSort(String s) 
    {
        // Using bucket sort -- Not Optimal just for practice.
        Map<Character,Integer> freqMap = new HashMap<>();
        for(int i=0;i<s.length();i++)
        {
            freqMap.put(s.charAt(i),freqMap.getOrDefault(s.charAt(i),0)+1);
        }
        List<Character>[] freqSorting = new List[s.length()+1];
        freqMap.forEach((k,v) -> {
            if (freqSorting[v] == null) {
                freqSorting[v] = new ArrayList<>();
            }
            freqSorting[v].add(k);
        });
        StringBuilder ans = new StringBuilder();
        for(int i=freqSorting.length-1;i>=0;i--)
        {
            if(freqSorting[i] == null)
                continue;
            for(int j=0;j<freqSorting[i].size();j++) 
            {
                for(int k=0;k<i;k++) 
                {
                    ans.append(freqSorting[i].get(j));
                }
            }
        }

        return ans.toString();
    }
    public String frequencySort(String s) {
        // return usingMaxHeap(s);
        return usingBucketSort(s);
    }
}