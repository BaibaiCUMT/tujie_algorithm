#include <vector>

//直接查找，速度还可以
class Solution {
public:
    bool findNumberIn2DArray(std::vector<std::vector<int>>& matrix, int target) 
    {
        bool find = false;
        for (int i = 0; i < matrix.size(); i++) 
        {
            for (int j = 0;  j < matrix[0].size(); j++) 
            {
                if ( matrix[i][j] == target ) find = true;
            }
        }
    return find;
    }
};



//按照这个矩阵的规律来找值，对于这种题目可以从四个角找他的规律；
class Solution2 {
public:
    bool findNumberIn2DArray(std::vector<std::vector<int>>& matrix, int target) 
    {
        //if (matrix.size()==0) return false; //当不用去空白区域的值时，不用验证了。
        int i = matrix.size() - 1;
        int j = 0;

        while ( i >= 0 && j < matrix[0].size() ) 
        {
            if ( matrix[i][j] > target ) i--;
            else if (matrix[i][j] < target) j++;
            else return true; 
            //else if (matrix[i][j] == target) return true;这句对于空白的矩阵还要取值，就会出现取空值的错误，反而不美。
        }
        return false;
    }
};