#include <vector>
#include <cstdlib>
#include <type_traits>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <ctime>

//****************************************************
template<typename T>
void quick_sort_recursive(T arr[], int start, int end) {
    if (start >= end) return;
    T mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right) left++;
        while (arr[right] >= mid && left < right) right--;
        std::swap(arr[left], arr[right]);
    }
    if (arr[left] >= arr[end])
        std::swap(arr[left], arr[end]);
    else
        left++;
    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

template<typename T>
void quick_sort(T arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}


//****************************************************
class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) 
    {
        myQuickSort(nums, 0,nums.size()-1);
        return nums;
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


//****************************************************
void quickSort(std::vector<int>& arr, int l, int r) {
        // 子数组长度为 1 时终止递归
        if (l >= r) return;
        // 哨兵划分操作（以 arr[l] 作为基准数）
        int i = l, j = r;
        while (i < j) {
            while (i < j && arr[j] >= arr[l]) j--;
            while (i < j && arr[i] <= arr[l]) i++;
            std::swap(arr[i], arr[j]);
        }
        std::swap(arr[i], arr[l]);
        // 递归左（右）子数组执行哨兵划分
        quickSort(arr, l, i - 1);
        quickSort(arr, i + 1, r);
    }
