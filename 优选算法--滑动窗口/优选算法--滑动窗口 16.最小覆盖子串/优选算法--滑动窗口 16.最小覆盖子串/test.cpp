#define _CRT_SECURE_NO_WARNINGS 1

class Solution {
public:
    string minWindow(string s, string t) {
        int hash1[128] = { 0 }, kinds = 0;
        for (auto ch : t)
            if (hash1[ch]++ == 0) kinds++;
        int hash2[128] = { 0 };
        int minlen = INT_MAX, begin = -1;
        for (int left = 0, right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];
            if (++hash2[in] == hash1[in]) count++;
            while (count == kinds)
            {
                if (right - left + 1 < minlen)
                {
                    minlen = right - left + 1;
                    begin = left;
                }
                char out = s[left++];
                if (hash2[out]-- == hash1[out]) count--;
            }
        }
        return begin == -1 ? "" : s.substr(begin, minlen);
    }
};