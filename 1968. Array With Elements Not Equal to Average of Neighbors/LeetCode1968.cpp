#include<iostream>
#include<string>
#include<vector>
#include <algorithm>

using namespace std;

// 解讀題目後可知:只要符合i - 1、i + 1分別為一奇一偶就可得答案。

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int L = 1;

        while(L < nums.size() - 1)
        {
            if(nums[L - 1] < nums[L] && nums[L] < nums[L + 1] || nums[L - 1] > nums[L] && nums[L] > nums[L + 1])
                swap(nums[L], nums[L + 1]);

            L++;
        }

        return nums;
    }
};

int main()
{
    vector<int> nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    for(int num : AnswerFunction.rearrangeArray(nums))
        cout << num << " ";
}