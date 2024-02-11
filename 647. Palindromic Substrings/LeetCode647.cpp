#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int result = 0, n = s.size();

        for(int i = 0; i < n - 1; i++)
        {
            isPalindromic(i, i, result, s, n);
            isPalindromic(i, i + 1, result, s, n);
        }

        isPalindromic(n - 1, n - 1, result, s, n);
        return result;
    }

private:
    void isPalindromic(int first, int end, int &result, string &s, int n)
    {
        while(first >= 0 && end <= n - 1 && s[first] == s[end])
        {
            result++;
            first--;
            end++;
        }

        return;
    }
};