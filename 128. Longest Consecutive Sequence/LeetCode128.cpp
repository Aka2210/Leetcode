#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> records;
        int max = 0;

        for(int i = 0; i < nums.size(); i++)
            records[nums[i]] = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(records.find(nums[i] + 1) != records.end())
                records[nums[i]] = nums[i] + 1;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            int Continue = 1;
            
            records.erase(nums[i]);

            for(int j = 1; records.find(nums[i] + j) != records.end(); Continue++, j++)
                records.erase(nums[i] + j);

            for(int j = 1; records.find(nums[i] - j) != records.end(); Continue++, j++)
                records.erase(nums[i] - j);

            if(Continue > max)
                max = Continue;
        }

        return max;
    }
};

int main()
{
    vector<int> nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    cout << AnswerFunction.longestConsecutive(nums);
}