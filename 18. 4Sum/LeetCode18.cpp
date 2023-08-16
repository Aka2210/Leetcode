#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

// 寫不出Two Point解法。

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int j = nums.size() - 1, index = 0;

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        while(index < j)
        {
            int i = index + 1, k = j - 1, initSum = nums[k] + nums[index] + nums[i] + nums[j];

            while(i < k)
            {
                int sum = nums[k] + nums[index] + nums[i] + nums[j];
                if(sum > target)
                {
                    k--;

                    while(nums[k - 1] == nums[k] && i < k)
                        k--;
                }
                else if(sum < target)
                {
                    i++;

                    while(nums[i - 1] == nums[i] && i < k)
                        i++;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k], nums[index]});
                    k--;
                    i++;
                }
            }

            if(initSum == target)
            {
                j--;
                index++;

                while(nums[index - 1] == nums[index] && index < j)
                    index++;
                
                while(nums[j + 1] == nums[j] && index < j)
                    j--;
            }
            else if(initSum > target)
            {
                j--;
                while(nums[j + 1] == nums[j] && index < j)
                    j--;
            }
            else
            {
                index++;
                while(nums[index - 1] == nums[index] && index < j)
                    index++;
            }
        }

        return ans;
    }
};

int main()
{
    int target;
    cin >> target;
    vector<int>nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    for(vector<int> n : AnswerFunction.fourSum(nums, target))
    {
        for(int num : n)
            cout << num << " ";
        cout << endl;
    }

    cout << "Finish";
}