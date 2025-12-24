#define _CRT_SECURE_NO_WARNINGS 1
#include <vector>
using namespace std;

class Solution {
    vector<int> tmp;
public:
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize(nums.size());
        mergesort(nums, 0, nums.size() - 1);
        return nums;
    }

    void mergesort(vector<int>& nums, int left, int right)
    {
        if (left >= right) return;
        int mid = (right - left) / 2 + left;

        // [left, mid][mid + 1, right]
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);
        // 合并两个有序数组
        int begin1 = left, end1 = mid;
        int begin2 = mid + 1, end2 = right;
        int index = left;
        while (begin1 <= end1 && begin2 <= end2)
        {
            if (nums[begin1] < nums[begin2]) tmp[index++] = nums[begin1++];
            else tmp[index++] = nums[begin2++];
        }
        while (begin1 <= end1) tmp[index++] = nums[begin1++];
        while (begin2 <= end2) tmp[index++] = nums[begin2++];

        for (int i = left; i <= right; i++)
            nums[i] = tmp[i];
    }
};