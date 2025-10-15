#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int begin = 0, end = 0, mid = 0;
        if (nums.empty())
        {
            return { -1,-1 };
        }
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[left] == target) begin = left;
        else return{ -1,-1 };

        right = n - 1;
        while (left < right)
        {
            mid = left + (right - left + 1) / 2;
            if (nums[mid] > target) right = mid - 1;
            else left = mid;
        }
        if (nums[right] == target) end = right;
        else return { -1,-1 };

        return { begin,end };
    }
};