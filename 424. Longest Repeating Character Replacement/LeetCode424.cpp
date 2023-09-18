#include<iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>
#include<string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        char target = s[0];
        int L = 0, R = 0, ans = 0;
        unordered_map<char, int> records;

        while(R < s.length())
        {   
            records[s[R]]++;

            if(records[target] <= records[s[R]])
                target = s[R];
            
            if(k - R + L - 1 + records[target] < 0)
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