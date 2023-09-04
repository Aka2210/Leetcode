#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;

        while(nums.size() > 1 && L + 1 != R)
        {
            if(nums[(L + R) / 2] > target)
                R = (L + R) / 2;
            else if(nums[(L + R) / 2] < target)
                L = (L + R) / 2;
            else
                return (L + R) / 2;
        }

        if(nums[L] == target)
            return L;
        else if(nums[R] == target)
            return R;
        else
            return -1;
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

    cout << AnswerFunction.search(nums, val);
}