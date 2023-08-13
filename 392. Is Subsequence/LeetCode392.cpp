#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<string.h>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == "")
            return true;
            
        int Position = 0;

        for(char ch : t)
        {
            if(s[Position] == ch)
                Position++;
        }

        if(Position >= s.size())
            return true;
        else
            return false;
    }
};

int main()
{
    string s, t;

    cin >> s >> t;

    Solution AnswerFunction;

    if(AnswerFunction.isSubsequence(s, t))
        cout << "true";
    else
        cout << "false";
}