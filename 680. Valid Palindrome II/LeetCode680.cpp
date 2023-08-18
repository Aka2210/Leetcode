#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int L = 0, R = s.size() - 1;

        for(;L < R; L++, R--)
            if(s[L] != s[R])
                break;

        if(L < R)
        {
            string s1 = s.substr(L, R - L), s2 = s.substr(L+1, R - L);

            bool s1Detect = false, s2Detect = false;

            for(L = 0, R = s1.size() - 1;L < R; L++, R--)
            {
                if(s1[L] != s1[R])
                    s1Detect = true;

                if(s2[L] != s2[R])
                    s2Detect = true;
                    
                if(s1Detect && s2Detect)
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    string s;

    getline(cin, s);

    Solution AnswerFunction;

    if(AnswerFunction.validPalindrome(s))
        cout << "true";
    else
        cout << "false";
}