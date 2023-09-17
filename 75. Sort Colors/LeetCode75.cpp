#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int L = 0, r = nums.size() - 1, l = L;

        for(; L <= r; L++)
        {
            if(nums[L] == 0)
            {
                swap(nums[L], nums[l]);
                l++;
            }

            if(nums[L] == 2)
            { 
                swap(nums[L], nums[r]);
                r--;
                L--;
            }
        }
    }
};

int main()
{
    vector<int>nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    AnswerFunction.sortColors(nums);

    for(int num : nums)
        cout << num << " ";
}