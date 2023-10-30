#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int L = 0, R = 0, ans = 0;
        
        unordered_map<char, int> records;

        while(R < s.size())
        {
            if(records.find(s[R]) != records.end())
            {
                ans = max(ans, R - L);

                int move = records[s[R]] + 1;

                while(L != move)
                {
                    records.erase(s[L]);
                    L++;
                }
            }

            records[s[R]] = R;
            R++;
        }
        
        ans = max(ans, R - L);

        return ans;
    }
};

int main()
{
    string s;

    getline(cin, s);

    Solution AnswerFunction;

    cout << AnswerFunction.lengthOfLongestSubstring(s);

}