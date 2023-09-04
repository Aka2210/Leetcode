#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < target) {
                low = mid + 1;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        
        return -1;
    }
};

int main()
{
    vector<int> nums;

    int question, val;

    cin >> val;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    cout << AnswerFunction.search(nums, val);
}