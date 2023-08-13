#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<string.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        int a[26] = {0}, b[26] = {0};

        for(char c : s)
        {
            a[static_cast<int>(c) - 97]++;
        }

        for(char c : t)
        {
            b[static_cast<int>(c) - 97]++;
        }
        
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i]){
                return false;
            }
        }

        return true;
    }
};

int main()
{
    string s, t;

    cin >> s >> t;

    Solution AnswerFunction;

    if(AnswerFunction.isAnagram(s, t))
        cout << "true";
    else
        cout << "false";
}