#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

//也可用bucket sort搞定。

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> records;
        unordered_map<int, vector<int>> ans;
        unordered_set<int> judge;
        vector<int> result;
        int Max = 0;

        for(int num : nums)
            records[num]++;

        for(int num : nums)
        {
            if(judge.find(num) == judge.end())
            {
                ans[records[num]].push_back(num);
                Max = max(records[num], Max);
                judge.insert(num);
            }
        }

        for(int i = Max; k > 0; i--)
        {
            if(ans.count(i))
            {
                for(int num : ans[i])
                    result.push_back(num);

                k -= ans[i].size();
            }
        }

        return result;
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

    for(int num : AnswerFunction.topKFrequent(nums, val))
        cout << num << " ";
}