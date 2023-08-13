#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<string.h>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        bool OPEN = false;
        
        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] != ' ')
            {
                OPEN = true;
                ans++;
            }
            else if(s[i] == ' ' && OPEN)
                return ans;
        }

        return ans;
    }
};

int main()
{
    string s;

    getline(cin, s);

    Solution AnswerFunction;

    cout << AnswerFunction.lengthOfLastWord(s);

}