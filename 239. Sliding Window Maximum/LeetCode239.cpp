#include<iostream>
#include<vector>
#include<deque>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> records;

        for(int i = 0; i < nums.size(); i++)
        {
            while(!records.empty() && nums[i] > nums[records.back()])
                records.pop_back();

            while(!records.empty() && records.front() < i - k + 1)
                records.pop_front();

            records.push_back(i);

            if(i - k + 1 >= 0)
                ans.push_back(nums[records[0]]);
        }

        return ans;
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

    for(int num : AnswerFunction.maxSlidingWindow(nums, target))
        cout << num << " ";

}