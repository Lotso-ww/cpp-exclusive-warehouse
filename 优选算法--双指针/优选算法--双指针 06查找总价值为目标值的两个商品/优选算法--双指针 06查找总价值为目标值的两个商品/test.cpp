#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& price, int target) {
        int left = 0, right = price.size() - 1;
        while (left < right)
        {
            if (price[left] + price[right] < target) left++;
            else if (price[left] + price[right] > target) right--;
            else return{ price[left],price[right] };
        }
        return { -1,-1 };
    }
};