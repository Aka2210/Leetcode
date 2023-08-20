#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int L = 0, R = L + k - 1, res = 100000;

        for(;R < nums.size();L++, R++)
            res = min(res, nums[R] - nums[L]);

        return res;
    }
};

int main()
{
    vector<int> nums; 

    int question, val;

    cin >> val;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    cout << AnswerFunction.minimumDifference(nums, val);
}