#include<iostream>
#include<vector>
#include<deque>
#include <algorithm>

using namespace std;

// 利用sliding window的方式，範圍內抓到最大值之後使最大值i被dq.push_front()，接著將其他值都dq.push_back()，
// 若window還沒從最大值離開則持續使ans.push_back()最大值，若已經離開則進入下一個window的最大值。

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        deque<int> dq;

        for(int i = 0; i < nums.size(); i++)
        {        
            while(!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();
            
            while(!dq.empty() && nums[dq.back()] < nums[i])        
                dq.pop_back();

            dq.push_back(i);

            if(i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
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

    for(int num : AnswerFunction.maxSlidingWindow(nums, target))
        cout << num << " ";

}