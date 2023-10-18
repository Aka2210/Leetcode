#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        vector<vector<int>> result;
        dfs(candidates, target, curr, result, 0);
        return result;
    }

private:
    void dfs(vector<int>& candidates, int& target, vector<int>& curr, vector<vector<int>>& result, int start)
    {
        for(int i = start; i < candidates.size(); i++)
        {
            if(i > start && candidates[i] == candidates[i - 1])
                continue;
            
            target -= candidates[i];
            curr.push_back(candidates[i]);

            if(target <= 0)
            {
                if(target == 0)
                    result.push_back(curr);
                target += curr.back();
                curr.pop_back();
                break;
            }
            else
            {
                dfs(candidates, target, curr, result, i + 1);
                target += curr.back();
                curr.pop_back();
            }
        }
    }
};