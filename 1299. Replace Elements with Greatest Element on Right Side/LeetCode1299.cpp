#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

// 時間複雜度 O(n^2) 空間複雜度 O(n)

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans;

        for(auto it = arr.begin() + 1; it != arr.end(); it++)
            ans.push_back(*max_element(it, arr.end()));

        ans.push_back(-1);

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

    nums = AnswerFunction.replaceElements(nums);

    for(int num : nums)
        cout << num << ",";
}