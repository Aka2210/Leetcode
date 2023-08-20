#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<string.h>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int L = 0, R = 0;
        string ans = "";

        for(L = 0, R = 0; L < word1.length() && R < word2.length(); L++, R++)
        {
            ans += word1[L];
            ans += word2[R];
        }

        ans += word1.substr(L);
        ans += word2.substr(R);

        return ans;
    }
};

int main()
{
    string s, t;

    cin >> s >> t;

    Solution AnswerFunction;

    cout << AnswerFunction.mergeAlternately(s, t);
}