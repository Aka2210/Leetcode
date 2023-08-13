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
            if(record.find(t[i]) == record.end() && matched.find(s[i]) == matched.end()) //檢查是否雙方都沒有連接到的字母，若都沒有則進入if
            {
                record[t[i]] = s[i];
                matched.insert(s[i]);
            }
            else if(record[t[i]] != s[i]) // 如果當前與t[i]連接的字母不是這次的s[i]就代表t[i]會連接到第二個字母(此時就可以return false了)
            {                             // 但為了統一所以只給t[i] = #保證s一定不等於t，最後再return false;
                t[i] = '#';
                continue;
            }    

            t[i] = record[t[i]]; 
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