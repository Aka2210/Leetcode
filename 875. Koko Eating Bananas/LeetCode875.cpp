#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int MIN = 1e9, MAX = 0, mid;
        long int sum;

        if(piles.size() == 1)
        {
            MIN = 1;
            MAX = piles[0];
        }
        else
        {
            for(int i = 0; i < piles.size(); i++)
            {
                MIN = min(MIN, piles[i]);
                MAX = max(MAX, piles[i]);
            }
        }

        int ans = MAX;
        
        while(MIN <= MAX)
        {
            mid = MIN + (MAX - MIN) / 2;
            sum = 0;

            for(int i = 0; i < piles.size(); i++)
            {
                sum += ceil((double) piles[i] / mid);
            }

            if(sum <= h)
            {
                ans = min(ans, mid);
                MAX = mid - 1;
            }
            else
                MIN = mid + 1;
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

    cout << AnswerFunction.minEatingSpeed(nums, target);
}