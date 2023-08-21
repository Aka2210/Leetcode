#include<iostream>
#include<string>
#include<vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int L = 0, R = 0, ans = 1;

        while(R < nums.size())
        {
            if(nums[L] == nums[R])
                R++;
            else
            {
                L++;
                nums[L] = nums[R];
                ans++;
            }
        }

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
    
    cout << AnswerFunction.removeDuplicates(nums) << endl;

    for(int num : nums)
        cout << num << " ";
}