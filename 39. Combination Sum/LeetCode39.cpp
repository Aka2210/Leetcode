#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> currCombine;
        backTrack(0, 0, candidates, target, result, currCombine);

        return result;
    }

private:
    void backTrack(int start, int curr, vector<int>& candidates, int& target, vector<vector<int>>& result, vector<int>& currCombine)
    {
        for(int i = start; i < candidates.size(); i++)
        {
            curr += candidates[i];
            currCombine.push_back(candidates[i]);

            if(curr < target)
                backTrack(i, curr, candidates, target, result, currCombine);
            else if(curr == target)
            {
                result.push_back(currCombine);
                currCombine.pop_back();
                return;
            }
            else
            {
                currCombine.pop_back();
                return;
            }

            curr -= candidates[i];
            currCombine.pop_back();
        }
    }
};