#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> records;
        int ans = 0, n = heights.size();

        records.push({0, heights[0]});
        
        for(int i = 1; i < n; i++)
        {
            int index = i;
            while(!records.empty() && heights[i] < records.top().second)
            {
                ans = max(ans, records.top().second * (i - records.top().first));
                index = records.top().first;
                records.pop();
            }

            records.push({index, heights[i]});
        }

        while(!records.empty())
        {
            ans = max(ans, records.top().second * (n - records.top().first));
            records.pop();
        }

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

    cout << AnswerFunction.largestRectangleArea(nums);
}