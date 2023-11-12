#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string.h>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> record;
        unordered_set<char> matched;

        for(int i = 0; i < s.length(); i++)
        {
            if(record.find(s[i]) == record.end() && matched.find(t[i]) == matched.end()) //檢查是否雙方都沒有連接到的字母，若都沒有則進入if
            {
                record[s[i]] = t[i];
                matched.insert(t[i]);
            }
            else if(record[s[i]] != t[i]) // 如果當前與t[i]連接的字母不是這次的s[i]就代表t[i]會連接到第二個字母(此時就可以return false了)            
                return false;

            s[i] = record[s[i]]; 
        }

        return s == t;
    }
};

int main()
{
    string s, t;

    cin >> s >> t;

    Solution AnswerFunction;

    if(AnswerFunction.isIsomorphic(s, t))
        cout << "true";
    else
        cout << "false";
}