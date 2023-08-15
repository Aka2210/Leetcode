#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

// 沒寫出來QQQ

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        int n = nums.size();
        if (n < 3) {
            return result;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) { //若當前元素已經>0，那三個元素+起來不可能=0(j = i + 1且k>j)
                break;
            }
            if (i > 0 && nums[i - 1] == nums[i]) { //避免相同的結果
                continue;
            }
            
            int j = i + 1;
            int k = n - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    result.push_back({nums[i], nums[j], nums[k]});
                    
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    j++;
                    
                    while (j < k && nums[k - 1] == nums[k]) {
                        k--;
                    }
                    k--;
                }
            }
        }
        
        return result;
    }
};

int main()
{
    vector<int>nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    for(vector<int> n : AnswerFunction.threeSum(nums))
    {
        for(int num : n)
            cout << num << " ";
        cout << endl;
    }
}