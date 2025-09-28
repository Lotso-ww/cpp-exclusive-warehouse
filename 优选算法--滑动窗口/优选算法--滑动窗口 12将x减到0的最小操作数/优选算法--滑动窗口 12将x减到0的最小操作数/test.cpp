#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (auto a : nums) sum += a;
        int n = nums.size(), left = 0, right = 0, len = -1;
        int target = sum - x, desum = 0;
        if (target < 0) return -1;
        while (right < n)
        {
            desum += nums[right];
            while (desum > target)
            {
                desum -= nums[left++];
            }
            if (desum == target) len = max(len, right - left + 1);
            right++;
        }
        return len == -1 ? -1 : n - len;
    }
};