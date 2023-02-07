#include <vector>

class Solution {
public:
    int maxValue(std::vector<std::vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (i == 0 && j == 0) continue;;
                if (i == 0) grid[i][j] += grid[i][j-1];
                else if (j == 0) grid[i][j] += grid[i-1][j]; //这里使用else if 就可以，而多次使用if不行；因为使用else if 当i==0满足时，其他判断条件就不会被执行了，如果使用多次if，i==0执行完，仍然继续执行后面的语句，此时i=0，i-1是-1，根本找不到这个索引，就会报错了。
                else grid[i][j] += std::max(grid[i][j-1], grid[i-1][j]);
            }
        }
        return grid[m-1][n-1];
    }
};

//对于if else 的逻辑需要小心,想不明白的时候可以把条件写的很详细来避免错误；但是这样原来不用执行的语句也需要执行一次了，效率会变低。
class Solution2 {
public:
    int maxValue(std::vector<std::vector<int>>& grid) 
    {
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0) continue;
                if (i == 0) grid[i][j] = grid[i][j-1] + grid[i][j];
                if (j == 0) grid[i][j] = grid[i-1][j] + grid[i][j];
                else if (i > 0 && j > 0) grid[i][j] = std::max(grid[i-1][j], grid[i][j-1]) + grid[i][j];
            }
        }
        return grid[m-1][n-1];
    }
};