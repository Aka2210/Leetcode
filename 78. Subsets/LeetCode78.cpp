#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        push(result, {}, nums, 0);
        return result;
    }

private:
    void push(vector<vector<int>>& result, vector<int> curr, vector<int>& nums, int index)
    {
        if(index == nums.size())
        {
            result.push_back(curr);
            return;
        }

        push(result, curr, nums, index + 1);
        curr.push_back(nums[index]);
        push(result, curr, nums, index + 1);
        return;
    }
};