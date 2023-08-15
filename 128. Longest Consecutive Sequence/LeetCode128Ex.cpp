#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// 用if限制n一定在最小的位置，只需要由小往大計算連續性就好，比我的方法(抓到某一個數字後開始向左、向右同時搜尋，搜尋完後再刪除元素)
// 使用的時間更少而且比較直觀。

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        int longest = 0;
        for(auto &n: s){
            //if this is the start of the sequence
            if(!s.count(n - 1)){
                int length = 1; 
                while(s.count(n + length))
                    ++length;
                longest = max(longest, length);
            } 

        }
        return longest;
    }
};

int main()
{
    vector<int> nums;

    int question;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    cout << AnswerFunction.longestConsecutive(nums);
}