#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> deck;
        vector<int> ans;
        int amount = 0;
        unordered_map<int, int> records;
        
        deck.push(temperatures.back());
        ans.push_back(0);

        records[temperatures.back()] = temperatures.size() - 1;
        
        for(int i = temperatures.size() - 2; i >= 0; i--)
        {
            records[temperatures[i]] = i;

            if(temperatures[i] >= deck.top())
            {
                while(!deck.empty() && temperatures[i] >= deck.top())
                    deck.pop();

                if(!deck.empty())
                    ans.push_back(records[deck.top()] - i);
                else
                    ans.push_back(0);

                deck.push(temperatures[i]);
            }
            else
            {
                deck.push(temperatures[i]);
                ans.push_back(1);
            }
        }

        reverse(ans.begin(), ans.end());

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

    for(int num : AnswerFunction.dailyTemperatures(nums))
        cout << num << " ";

}