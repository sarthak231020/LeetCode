class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        if(strs.size() == 1) 
            return 0;
        int cnt = 0;
        for(int col=0;col<strs[0].size();col++)  // col will be iterating through the cols
        {
            for(int row = 1;row<strs.size();row++) 
            {
                if(strs[row][col] < strs[row-1][col]) //it means that current gut is smaller than previous one.
                {
                    cnt++;
                    break;
                }
            }
        }
        
        return cnt;
    }
};