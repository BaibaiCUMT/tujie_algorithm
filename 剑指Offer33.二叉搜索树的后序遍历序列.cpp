#include <vector>
#include <unordered_map>

class Solution {
public:
    bool verifyPostorder(std::vector<int>& postorder) 
    {
        return recur(postorder, 0, postorder.size()-1);
    }

    bool recur(std::vector<int>& postorder, int left, int right)
    {
        if (left >= right) return true;
        int p = left;
        while (postorder[p] < postorder[right]) p++;
        int m = p;
        while (postorder[p] > postorder[right]) p++;
        return p == right && recur(postorder, left, m-1) && recur(postorder, m, right-1);
    }
};