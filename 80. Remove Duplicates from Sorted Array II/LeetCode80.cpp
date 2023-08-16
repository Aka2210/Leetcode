#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, j = nums.size() - 1;

        if(nums.size() > 2 && nums[0] == nums[j])
            return 2;

        while(i < j)
        {
            if(nums[i - 1] == nums[i + 1] && nums[i + 1] == nums[i])
            {
                i++;

                int changeNum = nums[i];

                while(i < j && nums[i] == changeNum)
                {
                    while(i < j && (nums[j] == changeNum || (nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2])))
                        j--;

                    if(nums[j] != changeNum)
                    {
                        swap(nums[i], nums[j]);
                        j--;
                        i++;
                    }
                }

                if(nums[j] == changeNum)
                    j--;
            }
            else
                i++;
        }

        sort(nums.begin(), nums.begin() + j + 1);

        return j + 1;
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