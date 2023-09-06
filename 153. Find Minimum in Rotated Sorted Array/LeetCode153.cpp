#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int L = 0, R = nums.size() - 1, MIN = nums[0];
        
        while(L <= R)
        {
            int mid = L + (R - L) / 2;

            if(nums[mid] < MIN)
            {
                R = mid - 1;
                MIN = nums[mid];
            }
            else if(nums[mid] >= MIN)
                L = mid + 1;
        }

        return MIN;
    }
};

int main()
{
    vector<int>nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    cout << AnswerFunction.findMin(nums);
}