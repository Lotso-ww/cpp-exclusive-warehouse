#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        //≈≈–Ú
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n;)//πÃ∂® ˝a
        {
            if (nums[i] > 0) break;
            int left = i + 1, right = n - 1, target = -nums[i];
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum < target) left++;
                else if (sum > target) right--;
                else {
                    ret.push_back({ nums[i],nums[left],nums[right] });
                    left++, right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
            i++;
            while (i < n && nums[i] == nums[i - 1]) i++;
        }
        return ret;
    }
};