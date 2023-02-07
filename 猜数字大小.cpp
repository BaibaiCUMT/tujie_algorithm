/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 */
 int guess(int num);
 

class Solution {
public:
    int guessNumber(int n) 
    {
        int i = 0, j = n;
        while ( i <= j)
        {
            int m = i + ((j-i)>>1);
            if (guess(m) == -1) j = m-1;
            else if (guess(m) == 1) i = m+1;
            else if (guess(m) == 0) return m;
        }
        return 0;
    }
};