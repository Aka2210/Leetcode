#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

int dp[1001];

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++)
        {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        
        return min(dp[n - 1], dp[n - 2]);
    }
};