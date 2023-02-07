#include <iostream>


//这个方法是对的，但是对于极端的大小无法处理
class Solution {
public:
    double myPow(double x, int n) 
    {
        if (n == 0) return 1;
        if (n > 0) return recur(x, n);
        else if (n < 0)
        {
            n = -n;
            return 1 / recur(x, n);
        }
        return 0;
    }

    double recur(double x, int n)
    {
        if (n == 0) return 1;
        return x * recur(x, n-1);
    }
};


//快速幂解析的简单版本
class Solution2 {
public:
    double myPow(double x, int n) 
    {
        long b = n;
        double res = 1;
    
        if (b < 0)
        {
            b = -b;
            x = 1 / x;
        }
        
        while (b > 0) 
        {
            if ( b % 2 == 1) res *= x;
            x *= x;
            b = b / 2;
        }
        return res;
    }
};

//快速幂解析的位运算版本
class Solution21 {
public:
    double myPow(double x, int n) {
        if(x == 0.0f) return 0.0;
        long b = n;
        double res = 1.0;
        if(b < 0) {
            x = 1 / x;
            b = -b;
        }
        while(b > 0) {
            if((b & 1) == 1) res *= x;
            x *= x;
            b >>= 1;
        }
        return res;
    }
};


class Solution3 {
public:
    double myPow(double x, int n) 
    {
        if (x == 0) return 0;

        long b = n;
        double res = 1;

        if (b < 0)
        {
            b = -b;
            x = 1 / x;
        }

        while (b > 0) 
        {
            if ((b % 2) == 1) res *= x;
            x *= x;
            b /= 2;
        }
        return res;
    }
};