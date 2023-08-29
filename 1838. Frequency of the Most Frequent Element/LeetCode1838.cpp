#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        long long int ans = 0, L = 0, R = 1;
        
        if(nums.size() == 1)
            return 1;

        sort(nums.begin(), nums.end());

        while(R < nums.size())
        {
            k -= (nums[R] - nums[R - 1]) * (R - L);

            while(k < 0)
            {
                k += (nums[R] - nums[L]);
                L++;
            }

            ans = max(ans, R - L + 1);

            R++;
        }

        return ans;
    }
};

int main()
{
    vector<int> nums;

    int question, val;

    char space;

    cin >> val;

    while(cin >> question >> space)
        nums.push_back(question);

    Solution AnswerFunction;

    cout << AnswerFunction.maxFrequency(nums, val);
}