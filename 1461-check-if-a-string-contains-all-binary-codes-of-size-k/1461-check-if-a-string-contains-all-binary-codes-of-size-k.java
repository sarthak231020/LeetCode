class Solution {

    public int convertToDecimal(String s)
    {
        int n = s.length();
        int j = 0;
        int ans = 0;
        for(int i=n-1;i>=0;i--)
        {
            ans += (s.charAt(i)-'0')*(int)Math.pow(2,j++);
        }
        return ans;
    }

    public boolean hasAllCodes(String s, int k) {
        int n = s.length();
        if(k > n) 
            return false;
        // int[] freq = new int[(int)Math.pow(2,k)]; // For brut
        int i = 0, j = 0;
        Set<String> st = new HashSet<>();

        while(j < n) 
        {
            if(j-i+1 == k) 
            {
                // freq[convertToDecimal(s.substring(i,j+1))]++; // For Brut
                st.add(s.substring(i,j+1));
                i++;
            }
            j++;
        }
        return st.size() == (int)Math.pow(2,k);
    }
}