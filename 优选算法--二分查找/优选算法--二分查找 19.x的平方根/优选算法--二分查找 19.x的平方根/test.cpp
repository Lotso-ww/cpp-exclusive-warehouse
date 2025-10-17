#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 1) return 0;
        int left = 1, right = x;
        while (left < right)
        {
            long long mid = left + (right - left + 1) / 2;
            if (mid * mid <= x) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};