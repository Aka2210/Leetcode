#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int L = 0, R = people.size() - 1, ans = 0;
        
        sort(people.begin(), people.end());

        for(;L <= R; R--)
        {
            if(people[L] + people[R] <= limit)
                L++;

            ans++;
        }

        return ans;
    }
};

int main()
{
    int target;
    cin >> target;
    vector<int>nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    cout << AnswerFunction.numRescueBoats(nums, target);
}