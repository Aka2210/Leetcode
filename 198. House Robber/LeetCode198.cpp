#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp;
        int n = nums.size();

        if(n == 1)
            return nums[0];
            
        dp.push_back(nums[0]);
        dp.push_back(max(nums[0], nums[1]));

        for(int i = 2; i < n; i++)
        {
            dp.push_back(max(dp[i - 2] + nums[i], dp[i - 1]));
        }

        return dp.back();
    }
};