#include<iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
     vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp; // val -> index

        for (int i = 0; i < n; i++) {
            int compliment = target - nums[i];
            if (mp.find(compliment) != mp.end()) {
                return {mp[compliment], i};
            }
            mp.insert({nums[i], i});
        }
        return {};
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