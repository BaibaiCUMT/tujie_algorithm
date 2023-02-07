#include <cstddef>
#include <vector>


//为啥没人用递归呢？
//递归这法子做这题不好，因为对于每个数，他都是按照→↓←↑的顺序来前进的，圈数大之后按照这个顺序继续前进，就会出错。
//他们使用了一个判断，当开始向上的时候就只能向上，来解决问题，但我没懂
class Solution {
public:
    std::vector<int> res;
    std::vector<std::vector<int>> matrix1;
    int m, n;
    
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) 
    {
        if (matrix.empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();

        this->matrix1 = matrix;
        this->m = m;
        this->n = n;
        bfs(0, 0);
        return res;
    }

    void bfs(int i, int j)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || matrix1[i][j] == 0x3f3f3f3f) return;
        res.push_back(matrix1[i][j]);
        matrix1[i][j] = 0x3f3f3f3f;
        //这里使用++和+1结果是不一样的，不明白为啥
        bfs(i,j+1);
        bfs(i+1, j);
        bfs(i, j-1);
        bfs(i-1, j);
    }
};



class Solution2 {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) 
    {
        if (matrix.empty()) return {};
        int left = 0, right = matrix[0].size()-1, top = 0, bottom = matrix.size()-1;
        std::vector<int> res;

        while (true) 
        {
            for (int i = left; i <= right; i++) res.push_back(matrix[top][i]);
            if (++top > bottom) break;

            for (int i = top; i <= bottom; i++) res.push_back(matrix[i][right]);
            if (--right < left) break;

            for (int i = right; i >= left; i--) res.push_back(matrix[bottom][i]);
            if (--bottom < top) break;

            for (int i = bottom; i >= top; i--) res.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return res;
    }
};