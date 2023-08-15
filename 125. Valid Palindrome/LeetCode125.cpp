#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<string.h>

using namespace std;

// 許多常見功能可以使用內建函式，使用後程式會更易讀。

class Solution {
public:
    bool isPalindrome(string s) {
        string ansForward, ansBackward;

        for(int i = 0, j = s.size() - 1; i < s.size(); i++, j--)
        {
            while(j >= 0 && !((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9')))
                j--;

            if(j == -1)
                break;

            if(s[j] >= 'A' && s[j] <= 'Z')
                s[j] -= ('A' - 'a');

            while(i < s.size() && !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')))
                i++;

            if(i == s.size())
                break;
            
            if(s[i] >= 'A' && s[i] <= 'Z')
                    s[i] -= ('A' - 'a');

            if(s[i] != s[j])
                return false;
        }
        
        return true;
    }
};

int main()
{
    string s;

    getline(cin, s);

    Solution AnswerFunction;

    if(AnswerFunction.isPalindrome(s))
        cout << "true";
    else
        cout << "false";
}