#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

// 沒寫出來QQQ，因為三個數可以互換，所以其實forward可以設定為必定在index前方，其他思路就沒問題了，有問題的是實作的小細節。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_set<int> records;

        sort(nums.begin(), nums.end());
        
        int forward = 0, backward = nums.size() - 1;

        vector<vector<int>> ans;

        for(int index = 0; index < nums.size(); index++)
        {   
            if(records.find(nums[index]) != records.end())
                continue;
                
            while(forward != backward)
            {
                if(forward == index)
                    forward++;

                if(backward == index)
                    backward--;

                if(nums[forward] + nums[backward] > -nums[index])
                    backward--;
                else if(nums[forward] + nums[backward] < -nums[index])
                    forward++;
                else
                {
                    ans.push_back({nums[forward], nums[backward], nums[index]});
                    forward++;
                }
            }

            records.insert(nums[index]);

            forward = 0;
            backward = nums.size() - 1;
        }

        return ans;
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