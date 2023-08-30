#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int L = 0, R = 1, amount = 0, recordAmount = 0, begin = 0, length = s.size() + 1;
        unordered_map<char, int> records, judge;

        for(char ch : t)
        {
            judge[ch]++;
            amount++;
        }

        if(judge[s[L]] && records[s[L]] < judge[s[L]])
        {
            records[s[L]]++;
            recordAmount++;
        }

        while(!(R >= s.size() && amount != recordAmount))
        {
            if(amount == recordAmount)
            {
                
                if(R - L < length)
                {
                    length = R - L;
                    begin = L;
                }

                if(judge[s[L]] && records[s[L]] <= judge[s[L]])
                    recordAmount--;

                records[s[L]]--;

                L++;
            }
            else
            {
                if(judge[s[R]] && records[s[R]] < judge[s[R]])
                    recordAmount++;

                records[s[R]]++;

                R++;
            }
        }

        string ans = s.substr(begin, length);

        if(length == s.size() + 1)
            ans = "";

        return ans;
    }
};

int main()
{
    string s, t;

    cin >> s >> t;

    Solution AnswerFunction;

    cout << AnswerFunction.minWindow(s, t);
}