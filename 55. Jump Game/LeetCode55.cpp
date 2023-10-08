#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int stop = nums[0];

        for(int i = 0; i < min(stop + 1, (int)nums.size()); i++)
        {
            stop = max(stop, nums[i] + i);
        }

        return stop >= nums.size() - 1 ? true : false;
    }
};