#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        unordered_set<int> records;
        backTrack(result, nums, curr, records);
        return result;
    }

private:
    void backTrack(vector<vector<int>>& result, vector<int>& nums, vector<int>& curr, unordered_set<int>& records)
    {
        if(curr.size() == nums.size())
        {
            result.push_back(curr);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(records.find(nums[i]) != records.end())
                continue;
            else
            {
                curr.push_back(nums[i]);
                records.insert(nums[i]);
                backTrack(result, nums, curr, records);
            }
            curr.pop_back();
            records.erase(nums[i]);
        }
    }
};