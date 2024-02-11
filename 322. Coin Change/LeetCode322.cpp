#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp;
        dp.push_back(0);

        for(int i = 1; i <= amount; i++)
        {
            dp.push_back(INT32_MAX);
            for(int j = 0; j < n; j++)
            {
                int Find = i - coins[j];
                if(Find < 0) continue;
                else if(dp[Find] != -1) dp[i] = min(dp[i], dp[Find] + 1);
            }

            if(dp[i] == INT32_MAX)
                dp[i] = -1;
        }

        return dp[amount];
    }
};