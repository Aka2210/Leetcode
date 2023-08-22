#include<iostream>
#include<string>
#include<vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MIN = prices[0], MAX = 0, ans = 0;

        for(int i = 0; i < prices.size(); i++)
        {
            if(prices[i] < MIN)
            {
                MIN = prices[i];  
                MAX = prices[i]; 
            } 
            else if(prices[i] > MAX)
                MAX = prices[i];

            ans = max(ans, MAX - MIN);
        }

        return ans;
    }
};

int main()
{
    vector<int> nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;
    
    cout << AnswerFunction.maxProfit(nums);
}