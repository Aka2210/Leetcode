#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> open;
        unordered_map<char, char> parens = {
            {')', '('},
            {']', '['},
            {'}', '{'},
        };
        
        for (const auto& c : s) {
            if (parens.find(c) != parens.end()) {
                // if input starts with a closing bracket.
                if (open.empty()) {
                    return false;
                }

                if (open.top() != parens[c]) {
                    return false;
                }

                open.pop();
            } else {
                open.push(c);
            }
        }
        
        return open.empty();
    }
};

int main()
{
    string s;

    getline(cin, s);

    Solution AnswerFunction;

    if(AnswerFunction.isValid(s))
        cout << "true";
    else
        cout << "false";
}