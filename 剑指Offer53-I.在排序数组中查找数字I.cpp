#include <vector>
#include <map>
#include <iostream>

class Solution {
public:
    int search(std::vector<int>& nums, int target) 
    {
        std::map<int,int> m1;
        for(int num : nums)
        {
            if (m1[num]) 
            {
                m1[num]++;
            }
            else 
            {
                m1[num] = 1;
            }
        }
        
        if (m1[target])
        {
            return m1[target];
        }
        return 0;
    }
};

//第二个答案同样可以获得正确的结果，但是找8指向的位置并不是8的右侧结果10，而是最右侧的一个8，同样对于7找的的结果不是8，而是最右侧的一个7
//找不到target-1时，依然可以找到target-1应该在队列中的位置
class Solution2 {
public:
    int search(std::vector<int>& nums, int target) 
    {
        return findRight(nums, target) - findRight(nums, target-1);
    }

    int findRight(std::vector<int>& nums, int tar)
    {
        int left = -1, right = nums.size();
        
        while (left+1 != right) 
        {
            int m = left + ((right - left) >> 1);
            if (nums[m] <= tar) left = m;
            else right = m;
        }
        return left;
    }
};

//我使用了左开右开来做题，结果findright运作良好，而findleft不太行
//这是为啥呢？
//findleft找到的根本不是8的长度，例如现在找7找到7的左侧第一个数5，找8找到8前的第一个数7，两个数字剪掉是7的长度
//换成这样就能过了
// class Solution {
// public:
//     int search(std::vector<int>& nums, int target) 
//     {
//         return findLeft(nums, target +1 ) - findLeft(nums, target);
//     }

//     int findLeft(std::vector<int>& nums, int tar)
//     {
//         int i = -1, j = nums.size();

//         while (i+1 != j)
//         {
//             int m = i + ((j-i)>>1);
//             if (nums[m] >= tar) j = m;
//             else i = m;
//         }
//         return j;
//     }
// };

class Solution3 {
public:
    int search(std::vector<int>& nums, int target) 
    {
        // cout << findLeft(nums, target) << endl;
        // cout << findLeft(nums, target-1) << endl;
        // return 0;
        // return findLeft(nums, target) - findLeft(nums, target-1);
        // return findRight(nums, target) - findRight(nums, target-1);
    }

    int findRight(std::vector<int>& nums, int tar)
    {
        int i = -1, j = nums.size();

        while (i+1 != j)
        {
            int m = i + ((j-i)>>1);
            if (nums[m] <= tar) i = m;
            else j = m; 
        }
        return j;
    }
    
    int findLeft(std::vector<int>& nums, int tar)
    {
        int i = -1, j = nums.size();

        while (i+1 != j)
        {
            int m = i + ((j-i)>>1);
            if (nums[m] >= tar) j = m;
            else i = m;
        }
        return j;
    }
};