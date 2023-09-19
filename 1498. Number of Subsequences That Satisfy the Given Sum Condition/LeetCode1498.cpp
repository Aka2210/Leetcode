#include<iostream>
#include<vector>
#include<math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        int L = 0, R = nums.size() - 1;
        int mod = 1e9+7;
        long long ans = fastPower(2, nums.size(), mod) - 1;
        
        while (L <= R) {
            if (nums[L] + nums[R] <= target) {
                L++;
            } else {
                ans = (ans - fastPower(2, R - L, mod) + mod) % mod;
                R--;
            }
        }
        
        return ans;
    }
    
    long long fastPower(long long base, int exp, int mod) {
        long long result = 1;
        while (exp) {
            if (exp & 1) result = (result * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return result;
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

    cout << AnswerFunction.numSubseq(nums, target);
}