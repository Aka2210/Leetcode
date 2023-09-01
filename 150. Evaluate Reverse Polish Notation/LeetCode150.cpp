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
        stack<int> deck;

        for(int i = 0; i < tokens.size(); i++)
        {
            int num1, num2;

            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
                deck.push(stringToVal(tokens[i]));
            else
            {
                num2 = deck.top();
                deck.pop();
                num1 = deck.top();
                deck.pop();

                if(tokens[i] == "+")
                    deck.push(num1 + num2);
                else if(tokens[i] == "-")
                    deck.push(num1 - num2);
                else if(tokens[i] == "*")
                    deck.push(num1 * num2);
                else if(tokens[i] == "/")
                    deck.push(num1 / num2);
            }
        }

        return deck.top();
    }

private:
    int stringToVal(string str)
    {
        int sum = 0, i = str[0] == '-' ? 1 : 0;

        while(i < str.size())
        {
            int now = (str[i] - '0');

            int j = 0;

            while(j < str.size() - 1 - i)
            {
                now *= 10;
                j++;
            }
            
            sum += now;
            i++;
        }

        if(str[0] == '-')
            sum *= (-1);
        
        return sum;
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