#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<string.h>

using namespace std;

// 事實上不需要preVal，完全可以用ans[i - 1][j + 1]代替掉

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans{{1}};
        int preVal = 1;

        for(int i = 1; i < numRows; i++)
        {
            ans.push_back({});
            preVal = 1;
            ans[i].push_back(1);
            for(int j = 0; j < i - 1; j++)
            {
                ans[i].push_back(ans[i - 1][j + 1] + preVal);
                preVal = ans[i - 1][j + 1];
            }
            ans[i].push_back(1);
        }

        for(vector<int> nums : ans)
        {
            for(int num : nums)
                cout << num << " ";
            cout << endl;
        }

        return ans;
    }
};

int main()
{
    int num;

    cin >> num;

    Solution AnswerFunction;

    AnswerFunction.generate(num);
}