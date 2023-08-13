#include<iostream>
#include<string>
#include<vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 1, zero = 0, zeroPos;
        vector<int> ans(nums.size(), 0);

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                zero++;
                zeroPos = i;
                continue;
            }
            total *= nums[i];
        }

        if(zero >= 2)
            return ans;
        else if(zero == 1)
        {
            ans[zeroPos] = total;
            return ans;
        }

        for(int i = 0; i < ans.size(); i++)
            ans[i] = total / nums[i];

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

    for(int num : AnswerFunction.productExceptSelf(nums))
        cout << num << " ";
}