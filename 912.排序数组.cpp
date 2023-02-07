#include <cstdlib>
#include <type_traits>
#include <utility>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <algorithm>


class Solution {
public:
    std::vector<int> sortArray(std::vector<int>& nums) 
    {
        myQuickSort(nums, 0,nums.size()-1);
        return nums;
    }

//冒泡***************************************************************************
    void bubbleSort(std::vector<int> &nums)
    {
        int n = nums.size();
        for (int j = 0; j < n-1; j++)
        {
            for (int i = 0; i < n-1; i++) 
            {
                if (nums[i] > nums[i+1]) 
                    std::swap(nums[i],nums[i+1]);
            }
        }  
    }

    //这个简洁很多
    void bubbleSortSample(std::vector<int> & nums)
    {
        int n = nums.size();
        for (int i = 0; i < n-1; i++) 
        {
            for (int j = 0; j < n-i-1; j++) 
            {
                if (nums[j] > nums[j+1]) 
                    std::swap(nums[j],nums[j+1]);
            }
        }
    }

    int partition(std::vector<int> &nums, int l, int r)
    {
        int i = l, j = r;
        while (i < j) 
        {
            while (i < j && nums[j] >= nums[l]) j--;
            while (i < j && nums[i] <= nums[l]) i++;
            std::swap(nums[i], nums[j]);
        }
        std::swap(nums[i], nums[l]);
        return i;
    }

    void quickSort(std::vector<int> &nums,int l, int r)
    {
        if (l >= r) return;
        int i = partition(nums, l, r);
        quickSort(nums, l, i-1);
        quickSort(nums, i+1, r);
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