#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

// 由多到少的問題可以試著讓它變成由少到多

// O(N) Time Complexity , O(1) Space complexity

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
      int n = arr.size();
      int maxSoFar = arr[n-1];
      arr[n-1] = -1;
      
      for(int i=n-2;i>=0;i--)
      {
        int temp = maxSoFar;
        if(maxSoFar < arr[i]) maxSoFar = arr[i];
        arr[i] = temp;
      }
      return arr;
    }
};

int main()
{
    vector<int> nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    nums = AnswerFunction.replaceElements(nums);

    for(int num : nums)
        cout << num << ",";
}