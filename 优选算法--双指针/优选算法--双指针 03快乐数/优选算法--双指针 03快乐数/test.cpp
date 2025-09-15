#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    int bitsum(int n)
    {
        int sum = 0;
        while (n)
        {
            int t = n % 10;
            sum += t * t;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = bitsum(n);
        while (slow != fast)
        {
            slow = bitsum(slow);
            fast = bitsum(bitsum(fast));
        }
        return slow == 1;
    }
};