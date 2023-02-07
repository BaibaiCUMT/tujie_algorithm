#include <vector>


//暴力解
class Solution {
public:
    std::vector<int> constructArr(std::vector<int>& a) 
    {
        std::vector<int> res;
        for (int i = 0; i < a.size(); i++) 
        {
            int tmp = 1;
            for (int j = 0; j < a.size(); j++) 
            {
                if (i == j) continue;
                tmp *= a[j];
            }
            res.push_back(tmp);
        }
        return res;
    }
};


class Solution2 {
public:
    std::vector<int> constructArr(std::vector<int>& a) 
    {
        int len = a.size();
        if (len == 0) return {};

        std::vector<int>left(len, 0), right(len, 0);
        std::vector<int>res(len, 0);

        left[0] = 1;
        for (int i = 1; i < len; i++) 
        {
            left[i] = a[i-1] * left[i-1];
        }

        right[len-1] = 1;
        for (int i = len-2; i >= 0; i--) 
        {
            right[i] = a[i+1] * right[i+1];
        }

        for (int i = 0; i < len; i++) 
        {
            res[i] = left[i] * right[i];
        }
        return res;
    }
};