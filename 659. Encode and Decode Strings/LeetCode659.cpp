#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

// 如果追求O(n)可以不將字母逐一編碼，只對字串+上特定符號(如Ex)，但我覺得很智障，所以用O(n^2)的方式。

class Solution {
public:
    string encode(vector<string> &strs) {
        string str = "";

        for(int i = 0; i < strs.size(); i++)
        {
            for(int j = 0; j < strs[i].size(); j++)
                str += (strs[i][j] - '#');
            
            str += ":;";
        }

        return str;
    }

    vector<string> decode(string &str) {
        vector<string> ans;
        string s = "";

        for(int i = 0; i < str.size(); i++)
        {
            if(str[i] == ':' && str[i + 1] == ';')
            {
                ans.push_back(s);
                s = "";
                i++;
                continue;
            }

            s += (str[i] + '#');
        }

        return ans;
    }
};

int main()
{
    vector<string> strs;

    string question;

    while(cin >> question)
    {
        if(question == "quit")
            break;

        strs.push_back(question);
    } 

    Solution AnswerFunction;

    string Encode = AnswerFunction.encode(strs);
    cout << Encode << endl;
    for(string str : AnswerFunction.decode(Encode))
        cout << str << " ";
}