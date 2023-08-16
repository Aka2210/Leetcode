#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

// 設L、R端，必定固定R為最後一個相同的數字，然後將L或L、L+1變為R，最後L++,R++，變成不同數字。
// 意義是說利用count做紀錄，紀錄當前數字出現的次數，若只有一次則R、L不動，然後nums[r] == nums[l]，
// 最後再同時+1，移動到下一個數字，若數字有兩個則count = 2，一樣的手段，而當同樣的數字大於2個的時候，因為min(count, 2)所以最多執行兩次，
// 兩次複製相同數字後L會移動到第三個相同的數字，而R會移動到下一個不同的數字，然後就可以讓r點的數字替換l點了(而且因為程式碼邏輯，r點會固定在下一個數字
// 的末端)，所以當兩次複製後，會跑到第二次不同的數字(以此來解決0 0 0 0 0 2 2 3 3)的情況

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0;

        while(r < nums.size())
        {
            int count = 1;

            while(r + 1 < nums.size() && nums[r] == nums[r + 1])
            {
                count++;
                r++;
            }

            for(int i = 0; i < min(count, 2); i++)
            {
                nums[l] = nums[r];
                l++;
            }

            r++;
        }

        return l;
    }
};

int main()
{
    vector<int>nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    cout << AnswerFunction.removeDuplicates(nums);
}