#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int L = 0, R = 1;

        while(R < nums.size())
        {   
            if(nums[L] == 0)
            {
                if(nums[R] == 0)
                {
                    R++;
                    continue;
                }

                swap(nums[L], nums[R]);
            }
            else
                R++;

            L++;
        }
    }
};

int main()
{
    vector<int> nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    AnswerFunction.moveZeroes(nums);

    for(int num : nums)
        cout << num << " ";
}