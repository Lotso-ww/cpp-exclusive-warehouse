#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int cur = 0, dest = -1, n = arr.size();
        while (cur < n)
        {
            if (arr[cur]) dest++;
            else dest += 2;
            if (dest >= n - 1) break;
            cur++;
        }
        if (dest >= n)
        {
            arr[n - 1] = 0;
            dest -= 2;
            cur--;
        }
        while (cur >= 0)
        {
            if (arr[cur]) arr[dest--] = arr[cur];
            else {
                arr[dest--] = 0;
                arr[dest--] = 0;
            }
            cur--;
        }
    }
};