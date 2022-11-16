/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int i = 1;
        int j = n;
        int mid;
        int ans;
        while(true) 
        {
            mid = (j-i)/2+i;
            ans = guess(mid);
            if(ans == 0) 
                return mid;
            if(ans > 0) 
                i = mid+1;
            else if(ans < 0) 
                j = mid-1; 
        }
        return -1;
    }
};