class Solution {
    public String brut(String s) 
    {
        s = s.trim();
        String[] splitStrs = s.split(" ");
        int ind = 0;
        for(String str:splitStrs)
        {
            if(!str.trim().isEmpty())
                splitStrs[ind++] = str;
        }
        int i = 0, j = ind-1;
        while(i < j) 
        {
            String temp = splitStrs[i];
            splitStrs[i] = splitStrs[j];
            splitStrs[j] = temp;
            i++;
            j--;
        }
        StringBuilder ans = new StringBuilder();
        for(int k=0;k<ind;k++)
        {
            ans.append(splitStrs[k]);
            if(k != ind-1) 
                ans.append(" ");
        }
        return ans.toString();
    }
    public String reverseWords(String s) {
        return brut(s);
    }
}