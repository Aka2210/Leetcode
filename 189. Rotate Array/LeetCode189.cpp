#include<iostream>
#include<vector>

using namespace std;

// 有看詳解影片但沒看程式碼，之後複習可以自己再想一次試試。

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k == 0)
            return;

        k %= nums.size();

        int L = 0, R = nums.size() - 1;

        for(; L < R; L++, R--)
            swap(nums[L], nums[R]);
        
        for(L = 0, R = k - 1; L < R; L++, R--)
            swap(nums[L], nums[R]);
        
        for(L = k, R = nums.size() - 1; L < R; L++, R--)
            swap(nums[L], nums[R]);
    }
};

int main()
{
    vector<int> nums; 

    int question, val;

    cin >> val;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    AnswerFunction.rotate(nums, val);

    for(int num : nums)
        cout << num << " ";
}