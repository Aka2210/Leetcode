#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

// 因為題目限制所以只會有0、1、2排大小，所以只有1跟0換位或1跟2換位兩種情況。

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p1=0,p2=nums.size()-1;
        for(int i=p1;i<=p2;i++)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[p1]);
                p1++;
            }
            if(nums[i]==2)
            {
                swap(nums[i],nums[p2]);
                p2--;
                i--;
            }
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