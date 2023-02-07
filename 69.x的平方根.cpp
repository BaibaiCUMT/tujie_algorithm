class Solution {
public:
    int mySqrt(int x) 
    {
        if (x < 2) return x;
        int i = 0, j = x;
        while (i+1 != j) 
        {
            int m = i + ((j-i)>>1);
            if (m > x/m) j = m;
            else if (m <= x/m) i = m;
        }
        return  i ;
    }
};