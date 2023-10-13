#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::vector<int> curr;
        std::vector<std::vector<int>> res;
        helper(candidates, target, 0, curr, res);
        return res;
    }
private:
    void helper(std::vector<int>& cands, int target, int i, std::vector<int>& curr,  std::vector<std::vector<int>>& res) {
        if (i >= cands.size() || target < 0)
            return;

        if (target == 0) {
            res.push_back(curr);
            return;
        }

        curr.push_back(cands[i]);
        
        helper(cands, target - cands[i], i, curr, res);

        curr.pop_back();

        helper(cands, target, i + 1, curr, res);
    }
};