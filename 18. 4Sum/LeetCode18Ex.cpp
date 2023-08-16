#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

// 我的思路對一半，當Two Point大於兩個點時，可以利用int i,j,k,l;然後j = i + 1, k = j + 1然後利用k、l執行Two Point
// 簡單來說就是先簡化為兩個點最後當k、l交錯後，移動j值，當j值到達臨界值時改變i並重製j、k、l重複上述過程。

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int> > res;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j > (i + 1) && nums[j] == nums[j - 1])
                    continue;
                int l = j + 1, r = n - 1;
                while (l < r) {
                    long sm = (long)nums[i] + (long)nums[j] + (long)nums[l] + (long)nums[r];
                    if (sm == target) {
                        res.push_back(vector<int>{nums[i], nums[j], nums[l], nums[r]});
                        l += 1;
                        while (l < r && nums[l] == nums[l - 1])
                            l += 1;
                    }
                    else if (sm > target)
                        r -= 1;
                    else
                        l += 1;
                }
            }
        }
        return res;
    }
};

int main()
{
    int target;
    cin >> target;
    vector<int>nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    for(vector<int> n : AnswerFunction.fourSum(nums, target))
    {
        for(int num : n)
            cout << num << " ";
        cout << endl;
    }

    cout << "Finish";
}