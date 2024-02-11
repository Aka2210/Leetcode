#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

//字串創建、拼接導致效率比解答解法低，但估算起來仍都是O(n^2)

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), Max = 0;
        string center = "", result;

        for(int i = 0; i < n; i++)
        {
            int start = i, end = i;

            center = s[i];
            while(s[i] == s[i + 1])
            {
                center += s[i];
                i++;
                end++;
            }

            int detectStart = start - 1, detectEnd = end + 1;
            isPalindromic(s, n, center, detectStart, detectEnd);
            int length = detectEnd - detectStart - 1;

            if(length > Max)
            {
                Max = length;
                result = center;
            }
        }

        return result;
    }
private:
    void isPalindromic(string &s, int n, string &center, int &start, int &end)
    {
        while(start >= 0 && end < n)
        {
            if(s[start] == s[end])
            {
                center = s[start] + center + s[end];
                start--;
                end++;
            }
            else
                break;
        }

        return;
    }
};