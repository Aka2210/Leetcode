#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;

        for(int i = 0; i < 2; i++)
            for(int num : nums)
                ans.push_back(num);

        return ans;
    }
};

int main()
{
    vector<int> nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    nums = AnswerFunction.getConcatenation(nums);

    for(int num : nums)
        cout << num;
}