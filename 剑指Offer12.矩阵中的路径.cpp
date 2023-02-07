#include <vector>
#include <string>


// 用这个测试 [["A","B","C"],["D","E","F"],["G","H","I"]]
class Solution {
public:
    int rows, cols;

    bool exist(std::vector<std::vector<char>>& board, std::string word) 
    {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (dfs(board,word,i,j,0)) return true; //如果是false，就不返回，只有true返回；也就意味着
            }
        }
        return false;

    }

    bool dfs(std::vector<std::vector<char>>& board, std::string& word, int i, int j, int k)
    {
        if ( i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k] ) return false;
        if ( k == word.size()-1 ) return true;
        board[i][j] = '\0';
        bool res;
        res = dfs(board,word,i+1,j,k+1) || dfs(board,word,i-1,j,k+1) || dfs(board,word,i,j+1,k+1) || dfs(board,word,i,j-1,k+1);
        board[i][j] = word[k];
        return res;
    }
};


//不恢复的解法，会遇到几个CASE过不去的情况，具体为啥分析不来。
//按照使用数据的原则和dfs的模板，改过的数字都要改回去。

// [["C","A","A"],["A","A","A"],["B","C","D"]]
// "AAB"

//不恢复：“如果不把当前这条路径遍历过的元素还原回去，那这条路走不通的时候，它所遍历过的元素全为空，这让后面怎么玩。” 我想不明白
class Solution2 {
public:

    int rows, cols;

    bool exist(std::vector<std::vector<char>>& board, std::string word)  
    {
        rows = board.size();
        cols = board[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                return dfs(board,word,i,j,0); //直接return的话，如果是false就返回false，如果是true，就返回true；
            }
        }
        return false;
    }
    bool dfs(std::vector<std::vector<char>>& board, std::string& word, int i, int j, int k)
    {
        if ( i >= rows || i < 0 || j >= cols || j < 0 || board[i][j] != word[k] ) return false;
        if ( k == word.size()-1 ) return true;
        board[i][j] = '\0';
        return dfs(board,word,i+1,j,k+1) || dfs(board,word,i-1,j,k+1) || dfs(board,word,i,j+1,k+1) || dfs(board,word,i,j-1,k+1);
    }
};