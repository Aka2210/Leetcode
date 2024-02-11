#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0')
            return 0;

        int n = s.size();
        int pre = 1, curr = 1, next = 0;

        for(int i = 1; i < n; i++)
        {
            if(s[i] != '0')
                next += curr;
            
            if(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
                next += pre;

            if(next == 0)
                return 0;

            pre = curr;
            curr = next;
            next = 0;
        }

        return curr;
    }
};