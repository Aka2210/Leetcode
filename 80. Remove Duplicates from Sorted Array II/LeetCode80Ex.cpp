#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0;

        while(r < nums.size())
        {
            int count = 1;

            while(r + 1 < nums.size() && nums[r] == nums[r + 1])
            {
                count++;
                r++;
            }

            for(int i = 0; i < min(count, 2); i++)
            {
                nums[l] = nums[r];
                l++;
            }

            r++;
        }

        return l;
    }
};

int main()
{
    vector<int>nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    cout << AnswerFunction.removeDuplicates(nums);
}