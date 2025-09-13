#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0, dest = -1;
        while (cur < nums.size())
        {
            if (nums[cur])
            {
                swap(nums[++dest], nums[cur]);
            }
            cur++;
        }
    }
};