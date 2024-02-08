#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

int dp[46];

class Solution {
public:
    int climbStairs(int n) {
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};