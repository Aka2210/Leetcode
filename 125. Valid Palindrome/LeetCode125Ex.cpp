#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<string.h>

using namespace std;

// 更簡潔的寫法要使用內建函式跟使用while迴圈當作最外層。


class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        
        while (i < j) {
            while (!isalnum(s[i]) && i < j) {
                i++;
            }
            while (!isalnum(s[j]) && i < j) {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
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