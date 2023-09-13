#include<iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>

using namespace std;

// 此為暴力解(寫不出two point用法)。

class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0, R = height.size() - 1, Max = 0;

        while(L < R)
        {
            Max = max((R - L) * min(height[L], height[R]), Max);

            if(height[L] <= height[R])
                L++;
            else
                R--;
        }

        return Max;
    }
};

int main()
{
    vector<int>nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    cout << AnswerFunction.maxArea(nums);
}