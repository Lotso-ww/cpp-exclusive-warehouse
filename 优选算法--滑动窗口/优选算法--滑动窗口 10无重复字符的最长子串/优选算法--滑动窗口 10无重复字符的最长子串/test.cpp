#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[128] = { 0 };//数组模拟实现hash表
        int left = 0, right = 0, ret = 0;
        int n = s.size();
        while (right < n)
        {
            hash[s[right]]++;
            while (hash[s[right]] > 1)
            {
                hash[s[left++]]--;
            }
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};