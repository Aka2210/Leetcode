#include<iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>

using namespace std;

// O(nlogn)的特殊技巧

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());

        int i = 0, j = nums.size() - 1;

        while(true)
        {
            if(nums[i] + nums[j] < target)
                i++;
            else if(nums[i] + nums[j] > target)
                j--;
            else
                break;
        }

        auto firstPos = find(temp.begin(), temp.end(), nums[i]);

        if(nums[i] == nums[j])
            j = find(firstPos + 1, temp.end(), nums[j]) - temp.begin();
        else
            j = find(temp.begin(), temp.end(), nums[j]) - temp.begin();

        i = firstPos - temp.begin();

        if(j > i)
            return {i, j};
        else
            return {j, i};
    }
};

int main()
{
    vector<int>nums;

    int target, question;

    cin >> target;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    for(int num : AnswerFunction.twoSum(nums, target))
        cout << num << " ";

}