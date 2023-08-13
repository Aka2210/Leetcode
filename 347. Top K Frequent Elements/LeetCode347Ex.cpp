#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

// 更好的作法，用vector<vector<int>>代替multimap，因為multimap的insert是O(nlogn)，
// 因此使用vector<vector<int>>可以提高效率。
// 此方法為bucket sort的應用。
// 概念類似:當多對一時，將一作為key，將多放入陣列中，最後將整個陣列當成value。

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[nums[i]]++;
        }
        
        vector<vector<int>> buckets(n + 1);
        for (auto it = m.begin(); it != m.end(); it++) {
            buckets[it->second].push_back(it->first);
        }
        
        vector<int> result;
        
        for (int i = n; i >= 0; i--) {
            if (result.size() >= k) {
                break;
            }
            if (!buckets[i].empty()) {
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
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