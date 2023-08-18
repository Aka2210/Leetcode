#include<iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>

using namespace std;

// 只需要移動當前較小的柱子(因為較小的柱子限制了容器高度)，就可以利用Two Point得出最大值。

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        
        int curr = 0;
        int result = 0;
        
        while (i < j) {
            curr = (j - i) * min(height[i], height[j]);
            result = max(result, curr);
            
            if (height[i] <= height[j]) {
                i++;
            } else {
                j--;
            }
        }
        
        return result;
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