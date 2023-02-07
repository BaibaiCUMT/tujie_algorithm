#include <vector>
#include <algorithm>
#include <ctime>

//这个题拿来做排序练习

class Solution {
public:
    std::vector<int> getLeastNumbers(std::vector<int>& arr, int k) 
    {
        std::vector<int> res;
        std::sort(arr.begin(), arr.end());
        //for (int i = 0; i < k; i++) res.push_back(arr[i]);
        res.assign(arr.begin(), arr.begin()+k);
        return res;
    }
};

//自己写排序
class Solution2 {
public:
    std::vector<int> getLeastNumbers(std::vector<int>& arr, int k) 
    {
        std::vector<int> res;
        myQuickSort(arr, 0 ,arr.size()-1);
        res.assign(arr.begin(), arr.begin()+k);
        return res;
    }

    void myQuickSort(std::vector<int> &nums, int left, int right)
    {
        if (left >= right) return;
        int i = myPartition(nums, left, right);
        myQuickSort(nums, left, i-1);
        myQuickSort(nums, i+1, right);
    }

    int myPartition(std::vector<int> &nums, int left, int right)
    {
        //随机选择pivot
        srand( (unsigned int) time(NULL));
        int ra = left + std::rand() % (right - left + 1);
        std::swap(nums[left], nums[ra]);

        //使用第一个元素作为pivot
        int i = left, j = right;
        while (i < j) 
        {
            while (i < j && nums[j] >= nums[left]) j--;
            while (i < j && nums[i] <= nums[left]) i++;
            std::swap(nums[i], nums[j]);
        }
        std::swap(nums[i], nums[left]);
        return i;
    }
};