#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i = 0, j, k, h = nums.size() - 1, n = nums.size();
        vector<vector<int>> ans;

        for(i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for(j = i + 1; j < n - 2; j++)
            {
                if(j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                k = j + 1;
                h = n - 1;

                while(k < h)
                {
                    long int sum = nums[i] + nums[j] + nums[k] + nums[h];

                    if(sum > target)
                    {
                        while(h - 1 >= 0 && nums[h] == nums[h - 1])
                            h--;
                        h--;//-2 -1 0 0 1 2
                    }
                    else if(sum < target)
                    {
                        while(k + 1 < nums.size() && nums[k] == nums[k + 1])
                            k++;
                        k++;
                    }
                    else
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[h]});
                        while(k + 1 < nums.size() && nums[k] == nums[k + 1])
                            k++;
                        k++;
                        while(h - 1 >= 0 && nums[h] == nums[h - 1])
                            h--;
                        h--;
                    }
                }
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
}