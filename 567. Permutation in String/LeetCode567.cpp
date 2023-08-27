#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int L = 0, R = s1.size() - 1, ans = 0;
        unordered_map<char, int> records, Judge;

        if(s1.size() > s2.size())
            return false;

        for(char ch : s1)
            Judge[ch]++;

        for(int index = 0; index < s1.size(); index++)
        {
            records[s2[index]]++;

            if(records[s2[index]] <= Judge[s2[index]])
                ans++;
        }

        while(R < s2.size() - 1)
        {
            if(ans == s1.size())
                return true;
            else
            {
                if(Judge[s2[L]] && records[s2[L]] <= Judge[s2[L]])
                    ans--;

                records[s2[L]]--;

                records[s2[R + 1]]++;

                if(Judge[s2[R + 1]] && records[s2[R + 1]] <= Judge[s2[R + 1]])
                    ans++;
            }
            
            L++;
            R++;
        }
        
        if(ans == s1.size())
            return true;

        return false;
        
    }
};

int main()
{
    string s, t;

    cin >> s >> t;

    Solution AnswerFunction;

    if(AnswerFunction.checkInclusion(s, t))
        cout << "true";
    else
        cout << "false";
}