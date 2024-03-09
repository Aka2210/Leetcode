#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), m = wordDict.size();
        unordered_set<string> t;
        vector<bool> dp(n+1);
        dp[0] = true;
        for(int i = 0; i < m; i++)
        {
            t.insert(wordDict[i]);
        }

        for(int i = 1; i < n + 1; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(dp[j])
                {
                    string curr = s.substr(j, i - j);
                    if(t.find(curr) != t.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }

        return dp[n];
    }
};