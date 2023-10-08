#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], MAX = nums[0];

        for(int i = 1; i < nums.size(); i++)
        {
            if(sum + nums[i] >= nums[i])
                sum += nums[i];
            else
                sum = nums[i];

            MAX = max(sum, MAX);
        }

        return MAX;
    }
};