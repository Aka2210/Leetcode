#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

// fastPower主要只是用來計算a^b % mod而已，這邊的概念是指，若數列為2 3 3 4 6 7，當left,right為0,5時，
// 代表(2,2)為最基礎的一次，然後要不要3、要不要3、要不要4...直到7，意思就是1 * 2 * 2 * 2 * 2 * 2每一次的*2都代表
// 對應到陣列的那個數取或不取，最後就是總次數了。(乾，誰想得到= =) //重寫之後我很快就想到了，有進步，但那個fastPower真的很白癡= =。

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int left = 0, right = n - 1;
        int res = 0, mod = 1e9 + 7;
        while (left <= right) {
            if (nums[left] + nums[right] > target) {
                right--;
            } 
            else {
                res = (res + fastPower(2, right - left, mod)) % mod;
                left++;
            }
        }
        return res;
    }
    
    int fastPower(int a, int b, int mod) {
        long long ans = 1;
        long long base = a;
        while (b != 0) {
            if (b % 2 == 1) {
                ans = (ans * base) % mod;
            }
            base = (base * base) % mod;
            b /= 2;
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

    cout << AnswerFunction.numSubseq(nums, target);
}