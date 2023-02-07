#include <iostream>
#include <vector>


//无法处理特殊情况，[1,2,3] 和 [3,2,1]
//这是因为模板只能解决最基本的问题，对于这个问题，我们需要考虑每次条件判断的时候能完全排除哪些值，而不能直接使用模板。
class Solution {
public:
    int minArray(std::vector<int>& numbers) 
    {
        int i = 0, j = numbers.size()-1;

        while (i <= j) 
        {
            int m = (i+j) / 2;
            if (numbers[m] >= numbers[j]) i = m+1;
            else j = m-1;
        }
        return numbers[i];
    }
};

//我们将区间分成两个有序区间，一个左区间，一个右区间，目标是右区间首值
//对于m>j，m必然在左区间，我们放弃m和m左
//对于m<j，m必然在右区间，此时不能放弃m，只能放弃m右
//对于m == j，我们没法判断m在哪个区间，我们可以调整对比的对象来判断，j--
class Solution2 {
public:
    int minArray(std::vector<int>& numbers) 
    {
        int i = 0, j = numbers.size()-1;

        while (i <= j)
        {
            int m = (i + j) / 2;
            if (numbers[m] > numbers[j]) i = m + 1;
            else if (numbers[m] < numbers[j]) j = m;
            else if (numbers[m] == numbers[j]) j--;
        }
        return numbers[i];
    }
};