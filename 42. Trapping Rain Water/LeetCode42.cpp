#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0, R = height.size() - 1, sum = 0, borderL = height[L], borderR = height[R];

        while(L < R)
        {
            if(borderL < borderR)
            {
                L++;
                if(height[L] < borderL)
                    sum += borderL - height[L];
                else
                    borderL = height[L];
            }
            else
            {
                R--;
                if(height[R] < borderR)
                    sum += borderR - height[R];
                else
                    borderR = height[R];
            }
        }
        
        return sum;
    }
};

int main()
{
    vector<int>nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    cout << AnswerFunction.trap(nums);
}