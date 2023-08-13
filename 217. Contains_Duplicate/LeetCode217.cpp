#include<iostream>
#include<string>
#include<vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s; //建立集合
        
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) { //利用find尋找集合內的值，若有找到則回傳true
                return true;
            }
            s.insert(nums[i]); //將當前的值插入集合中
        }
        
        return false;
    }
};

int main()
{
    vector<int> nums;

    int question;

    char space;

    while(cin >> question)
        nums.push_back(question);

    Solution AnswerFunction;

    if(AnswerFunction.containsDuplicate(nums))
        cout << "true";
    else
        cout << "false";
}