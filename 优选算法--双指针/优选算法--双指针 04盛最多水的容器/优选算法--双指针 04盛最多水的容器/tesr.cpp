#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1, ret = 0;
        while (left < right)
        {
            int v = min(height[left], height[right]) * (right - left);
            ret = max(ret, v);
            if (height[left] < height[right]) left++;
            else right--;
        }
        return ret;
    }
};