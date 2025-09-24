#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0, len = 0, zero = 0;
        while (right < n)
        {
            if (nums[right] == 0) zero++;
            while (zero > k)
            {
                if (nums[left++] == 0) zero--;
            }
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};