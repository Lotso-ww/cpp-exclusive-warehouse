#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int hash1[26] = { 0 };
        for (auto ch : p) hash1[ch - 'a']++;
        int hash2[26] = { 0 };
        int n = s.size(), m = p.size();
        for (int left = 0, right = 0, count = 0; right < n; right++)
        {
            char in = s[right];
            if (++hash2[in - 'a'] <= hash1[in - 'a']) count++;
            if (right - left + 1 > m)
            {
                char out = s[left++];
                if (hash2[out - 'a']-- <= hash1[out - 'a']) count--;
            }
            if (count == m) ret.push_back(left);
        }
        return ret;
    }
};