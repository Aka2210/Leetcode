#include<iostream>
#include<vector>
#include<unordered_set>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1, MIN = nums[0], MinIndex = 0;
        
        while(L <= R)
        {
            int mid = L + (R - L) / 2;

            if(nums[mid] < MIN)
            {
                R = mid - 1;
                MIN = nums[mid];
                MinIndex = mid;
            }
            else if(nums[mid] >= MIN)
                L = mid + 1;
        }
        
        if(MIN <= target && target <= nums[nums.size() - 1] || MinIndex == 0)
        {
            L = MinIndex; 
            R = nums.size() - 1;
        }
        else if(nums[0] <= target && target <= nums[MinIndex - 1])
        {
            L = 0;
            R = MinIndex - 1;
        }
        else
            return -1;

        cout << L << " " << R << endl;

        while(L <= R)
        {
            int mid = L + (R - L) / 2;

            if(nums[mid] > target)
                R = mid - 1;
            else if(nums[mid] < target)
                L = mid + 1;
            else 
                return mid;
        }

        return -1;
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

    cout << AnswerFunction.search(nums, target);
}