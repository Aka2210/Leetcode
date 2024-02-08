#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

//第一格與最後一格只有三種情況，皆不搶、搶第一個不搶最後一個、搶最後一個不搶第一個
//皆不搶必定不是最大價值的搶法

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) 
        {
            return nums[0];
        }

        return max(robHouse(nums, 0, n - 2), robHouse(nums, 1, n - 1));
    }

private:
    int robHouse(vector<int> &nums, int first, int end)
    {
        int prev = 0;
        int curr = 0;
        int next = 0;
        
        for (int i = first; i <= end; i++) {
            next = max(prev + nums[i], curr);
            prev = curr;
            curr = next;
        }
        
        return curr;
    }
};