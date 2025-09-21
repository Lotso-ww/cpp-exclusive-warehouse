#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        //≈≈–Ú
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n;)
        {
            for (int j = i + 1; j < n;)
            {
                int left = j + 1, right = n - 1;
                long long targetsub = (long long)target - nums[i] - nums[j];
                while (left < right)
                {
                    long long sum = (long long)nums[left] + nums[right];
                    if (sum < targetsub) left++;
                    else if (sum > targetsub) right--;
                    else {
                        ret.push_back({ nums[i],nums[j],nums[left],nums[right] });
                        left++, right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    }
                }
                j++;
                while (j < n && nums[j] == nums[j - 1]) j++;
            }
            i++;
            while (i < n && nums[i] == nums[i - 1]) i++;
        }
        return ret;
    }
};