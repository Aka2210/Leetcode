#include<iostream>
#include<vector>
#include<unordered_map>
#include <algorithm>

using namespace std;

// vector的查找需要O(n)，因此此方法時間複雜度仍是O(n^2)。
// 無序哈希表的查找都是O(1)，有序的則是O(logn)，因此若要減少複雜度則要使用哈希表的方法

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++)
        {
            auto it = find(nums.begin(), nums.end(), target - nums[i]);

            int index = static_cast<int>(it - nums.begin());

            if(it != nums.end() && index != i)
            {
                if(i > it - nums.begin())
                    return {index, i};
                else
                    return {i, index};
            }
        }

        return {-1, -1};
    }
};

int main()
{
    vector<int>nums;

    int target, question;

    cin >> target;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    for(int num : AnswerFunction.twoSum(nums, target))
        cout << num << " ";

}