#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cmath>
#include <random>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
    }
};

int main()
{
    vector<string> nums;

    string question;

    int i = 0;

    while(cin >> question)
    {
        if(question == "quit")
            break;

        nums.push_back(question);
    }

    Solution AnswerFunction;

    cout << AnswerFunction.evalRPN(nums);
}