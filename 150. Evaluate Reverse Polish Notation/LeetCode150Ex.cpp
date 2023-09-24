#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for (int i = 0; i < tokens.size(); i++) {
            string token = tokens[i];
            
            if (token.size() > 1 || isdigit(token[0])) {
                stk.push(stoi(token));
                continue;
            }
            
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();
            
            int result = 0;
            if (token == "+") {
                result = num1 + num2;
            } else if (token == "-") {
                result = num1 - num2;
            } else if (token == "*") {
                result = num1 * num2;
            } else {
                result = num1 / num2;
            }
            stk.push(result);
        }
        
        return stk.top();
    }
};

int main()
{
    vector<string> nums;

    string question;

    int i = 0;

    while(cin >> question)
    {
        if(question == "quit")
            break;

        nums.push_back(question);
    }

    Solution AnswerFunction;

    cout << AnswerFunction.evalRPN(nums);
}