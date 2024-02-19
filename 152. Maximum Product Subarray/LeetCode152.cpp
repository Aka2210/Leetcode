#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;

//O(n^2)解的方法是利用雙重迴圈，由左至右每次選不同i作為起始點向右跑，遇到數字就相乘，然後跟當前max值比對，最後直接return max即可
//O(n)利用動態規劃提高效率的方法為: 紀錄由左到右當前所碰到的subarray的最大與最小值再根據遇到的新數字是正或負決定*最大或最小值以此來更新，然後每次迴圈都將result與當前最大值作比對紀錄，最後return result即可。


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), result = nums[0], Min = 1, Max = 1;

        for(int i = 0; i < n; i++)
        {
            int priorityMax = Max;
            Max = max(max(Min * nums[i], priorityMax * nums[i]), nums[i]); //因為必定*nums[i]或只留下nums[i]所以各數字必為subarray。
            Min = min(min(Min * nums[i], priorityMax * nums[i]), nums[i]);

            result = max(result, Max);
        }

        return result;
    }
};