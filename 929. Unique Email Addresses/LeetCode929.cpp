#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> s;

        for(int i = 0; i < emails.size(); i++)
        {
            string str = "";
            bool Add = false, Mouse = false;

            for(int j = 0; j < emails[i].length(); j++)
            {
                if(!Mouse)
                {
                    if(emails[i][j] == '@')
                    {
                        Mouse = true;
                        str += emails[i][j];
                        continue;
                    }

                    if(!Add)
                    {
                        if(emails[i][j] == '+')
                        {
                            Add = true;
                            continue;
                        }
                        else if(emails[i][j] == '.')
                            continue;  
                        
                        str += emails[i][j];
                    }
                    else
                        continue;
                }
                else
                    str += emails[i][j];
            }

            if(s.find(str) == s.end())
                s.insert(str);     
        }

        return s.size();
    }
};

int main()
{
    vector<string> emails;

    string question;

    while(cin >> question)
    {
        if(question == "quit")
            break;

        emails.push_back(question);
    }

    Solution AnswerFunction;

    cout << AnswerFunction.numUniqueEmails(emails);
}