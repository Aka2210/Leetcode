#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int index = nums.size() - k;
        return quickSelect(nums, index, 0, nums.size() - 1);
    }
private:
    int quickSelect(vector<int>& nums, int k, int l, int r){ //l、r代表左極、右極
        int pivot = nums[r];
        int p_pos = l;
        for (int i = l; i < r; ++i){ //從左極到右極判斷數值與pivot的關係
            if (nums[i] <= pivot){ 
                swap(nums[i], nums[p_pos]);
                ++p_pos; //此寫法使p_pos停留在第一個大於pivot的數字的位置
            }
        }
        swap(nums[p_pos], nums[r]); //將第一個大於pivot的數字與pivot數字的位置交換，使其呈現pivot左邊皆小於pivot，右邊皆大於pivot。
        if (k < p_pos)
            return quickSelect(nums, k, l, p_pos - 1);
        if (k > p_pos)
            return quickSelect(nums, k, p_pos + 1, r);
        return nums[p_pos];
    }
};