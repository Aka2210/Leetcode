#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> records;
        int result = 1;

        for(int i = 0; i < nums.size(); i++)
        {
            records.insert(nums[i]);

            while(records.find(result) != records.end())
                result++;    
        }

        return result;
    }
};