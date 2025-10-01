#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& f) {
        int hash[100001] = { 0 }, n = f.size();
        int left = 0, right = 0, kinds = 0, ret = 0;
        while (right < n)
        {
            if (hash[f[right]]++ == 0) kinds++;
            while (kinds > 2)
            {
                if (--hash[f[left++]] == 0) kinds--;
            }
            ret = max(ret, right - left + 1);
            right++;
        }
        return ret;
    }
};