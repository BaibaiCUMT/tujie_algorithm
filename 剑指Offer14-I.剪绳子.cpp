#include <iostream>
#include <cmath>
#include <math.h>

//先用不等式和求极值求出理想的长度

class Solution {
public:
    int cuttingRope(int n) 
    {
        if (n < 3) return n-1;
        int a = (n / 3);
        int b = (n % 3);
        if (b == 0) return pow(3,a);
        if (b == 1) return pow(3,a-1) * 4;
        // if (b == 2) 
        return pow(3, a) *2;
    }
};