#include<iostream>
#include<vector>
#include <algorithm>
#include <string>

using namespace std;

// 就算是O(n^2)也很小，所以可以直接O(n^2)解題避免浪費空間。

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1)
            return strs[0];
            
        int index, min = 201;

        for(int i = 0; i < strs.size(); i++)
            min = min > strs[i].length() ? strs[i].length() : min;

        int maxAnsLong = 201, ansLong = 0, i = 0;

        for(i = 0; i < min; i++)
        {
            for(int j = 1; j < strs.size(); j++)
            {
                if(strs[0][i] != strs[j][i])
                    return strs[0].substr(0, i);
            }
        }

        return strs[0].substr(0, i);
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

    for(char num : AnswerFunction.longestCommonPrefix(nums))
        cout << num;
}