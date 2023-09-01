#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, k;

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        while(i < nums.size() - 2)
        {
            if(nums[i] > 0)
                break;

            k = i + 1;
            
            j = nums.size() - 1;

            int sum = nums[i] + nums[j] + nums[k];

            while(k < j)
            {
                if(sum > 0)
                {
                    j--;

                    while(k < j - 1 && nums[j] == nums[j + 1])
                        j--;

                    sum = nums[i] + nums[j] + nums[k];
                }
                else if(sum < 0)
                {
                    k++;

                    while(k + 1 < j && nums[k] == nums[k - 1])
                        k++;
                        
                    sum = nums[i] + nums[j] + nums[k];
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    k++;

                    while(k < j && nums[k] == nums[k - 1])
                        k++;

                    sum = nums[i] + nums[j] + nums[k];
                }
            }

            i++;

            while(nums[i - 1] == nums[i] && i < nums.size() - 1)
                i++;
        }

        return ans;
    }
};

int main()
{
    vector<int>nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    for(vector<int> n : AnswerFunction.threeSum(nums))
    {
        for(int num : n)
            cout << num << " ";
        cout << endl;
    }
}