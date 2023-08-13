#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=val)
            {
                swap(nums[i],nums[count]);
                count++;
            }
        }
        
        return count;
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

    cout << AnswerFunction.removeElement(nums, val);
}