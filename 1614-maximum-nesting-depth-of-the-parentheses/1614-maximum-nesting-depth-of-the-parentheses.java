class Solution {
    public int maxDepth(String s) {
        int cnt = 0,ans = 0;
        for(int i=0;i<s.length();i++) 
        {
            if(s.charAt(i) == '(')
                cnt++;
            else if(s.charAt(i) == ')')
                cnt--;
            ans = Math.max(ans,cnt);
        }

        return ans;
    }
}