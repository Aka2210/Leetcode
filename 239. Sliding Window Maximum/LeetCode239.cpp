#include<iostream>
#include<vector>
#include<deque>
#include <algorithm>

using namespace std;

// Ex為解答，請自己再寫一次。

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

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