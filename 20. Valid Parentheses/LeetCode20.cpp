#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> deck;
        unordered_map<char, char> judge;
        unordered_map<char, int> records;

        judge[')'] = '(';
        judge[']'] = '[';
        judge['}'] = '{';
        judge['('] = ')';
        judge['['] = ']';
        judge['{'] = '}';

        char now;

        for(int i = 0; i < s.size(); i++)
        {
            now = s[i];
            deck.push(now);
            if(now == ')' || now == ']' || now == '}')
            {
                while(!deck.empty() && deck.top() != judge[now])
                {
                    deck.pop();

                    if(!deck.empty() && deck.top() != judge[now] && deck.top() != now)
                        return false;
                }

                if(deck.empty())
                    return false;
                else
                    deck.pop();     
            }
        }

        if(deck.empty())
            return true;
        else
            return false;
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