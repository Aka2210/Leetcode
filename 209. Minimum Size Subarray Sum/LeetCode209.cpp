#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0, R = 1, ans = nums.size() + 1;

        int sum = nums[0];

        while(L < R)
        { 
            if(sum < target)
            {
                if(R < nums.size())
                {
                    sum += nums[R];
                    R++;
                }
                else
                    L++;
            }
            else
            {
                ans = min(ans, R - L);
                sum -= nums[L];
                L++;
            }
        }

        if(ans == nums.size() + 1)
            ans = 0;

        return ans;
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

    cout << AnswerFunction.minSubArrayLen(val, nums);
}