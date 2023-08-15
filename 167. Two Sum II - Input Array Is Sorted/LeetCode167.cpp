#include<iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int forward = 0, backward = nums.size() - 1;

        while(forward != backward)
        {
            int cal = nums[forward] + nums[backward];

            if(cal > target)
                backward--;
            else if(cal < target)
                forward++;
            else
                return {++forward, ++backward};
        }

        return {-1, -1};
    }
};

int main()
{
    vector<int>nums;

    int target, question;

    cin >> target;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    for(int num : AnswerFunction.twoSum(nums, target))
        cout << num << " ";

}