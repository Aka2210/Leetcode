#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

// multimap的應用，若要使相同的key對應到不同的value則使用這個，且會自動排序(與map、set相同)，此解法為O(nlogn);
// 因為map、set、multimap都是基於紅黑樹的平衡二叉搜索樹實現的，因此他們的insert()皆為logn。

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> record;
        multimap<int, int, greater<int>> sort;
        vector<int> ans;

        for(int i = 0; i < nums.size(); i++)
            record[nums[i]] += 1;
        
        for(auto it = record.begin(); it != record.end(); it++)
            sort.insert({it->second, it->first});

        for(auto it = sort.begin(); k > 0; it++, k--)
            ans.push_back(it->second);

        return ans;
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