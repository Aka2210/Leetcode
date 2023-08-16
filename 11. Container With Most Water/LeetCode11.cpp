#include<iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>

using namespace std;

// 此為暴力解(寫不出two point用法)。

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;

        for(int i = 0, Pos = height.size() - 1; i < height.size(); i++)
        {
            if(i >= height.size() / 2)
                Pos = 0;
            else
                Pos = height.size() - 1;

            while(height[Pos] < height[i] && (Pos >= 0 || Pos < height.size()))
            {
                if(i >= height.size() / 2)
                    Pos++;
                else
                    Pos--;
            }

            if(Pos == -1)
                continue;

            if(height[i] * abs(Pos - i) > max)
                max = height[i] * abs(Pos - i);
        }

        return max;
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