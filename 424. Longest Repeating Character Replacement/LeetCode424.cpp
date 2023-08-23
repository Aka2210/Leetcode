#include<iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>
#include<string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, L = 0, R = 0, maxCount = 0;
        unordered_map<char, int> records;

        while(R < s.size())
        {
            records[s[R]]++;

            maxCount = max(maxCount, records[s[R]]);

            if(R - L + 1 - maxCount > k)
            {
                records[s[L]]--;
                L++;
            }

            ans = max(ans, R - L + 1);

            R++;
        }

        return ans;
    }
};

int main()
{
    int target;
    cin >> target;
    string s;

    cin>>s;

    Solution AnswerFunction;

    cout << AnswerFunction.characterReplacement(s, target);
}