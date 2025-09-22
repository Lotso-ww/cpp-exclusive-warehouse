#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), sum = 0, len = INT_MAX;
        for (int left = 0, right = 0; right < n; right++)
        {
            sum += nums[right];//进窗口
            while (sum >= target)
            {
                len = min(len, right - left + 1);//更新结果
                sum -= nums[left++];//出窗口
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};