#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

// 寫不出two point的方法所以用另一種O(n)代替。

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                zero++;
            else if(nums[i] == 1)
                one++;
            else
                two++;
        }

        nums.clear();

        while(zero > 0)
        {
            nums.push_back(0);
            zero--;
        }

        while(one > 0)
        {
            nums.push_back(1);
            one--;
        }

        while(two > 0)
        {
            nums.push_back(2);
            two--;
        }
    }
};

int main()
{
    vector<int>nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    AnswerFunction.sortColors(nums);

    for(int num : nums)
        cout << num << " ";
}