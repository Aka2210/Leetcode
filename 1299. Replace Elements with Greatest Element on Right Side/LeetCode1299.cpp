#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int Max = -1;

        for(int i = arr.size() - 1; i >= 0; i--)
        {
            int temp = arr[i];
            arr[i] = Max;
            Max = max(Max, temp);
        }

        return arr;
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