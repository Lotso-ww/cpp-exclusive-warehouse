#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        unordered_map<string, int> hash1;
        for (auto& s : words) hash1[s]++;

        int len = words[0].size(), m = words.size();
        for (int i = 0; i < len; i++)
        {
            unordered_map<string, int> hash2;
            for (int left = i, right = i, count = 0; right + len <= s.size(); right += len)
            {
                string in = s.substr(right, len);
                hash2[in]++;
                if (hash1.count(in) && hash2[in] <= hash1[in]) count++;
                if (right - left + 1 > len * m)
                {
                    string out = s.substr(left, len);
                    if (hash1.count(out) && hash2[out] <= hash1[out]) count--;
                    hash2[out]--;
                    left += len;
                }
                if (count == m)
                    ret.push_back(left);
            }
        }
        return ret;
    }
};