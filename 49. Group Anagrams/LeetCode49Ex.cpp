#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 將字母位置標出來就搞定了，我的方法只是標的方式不好，可以嘗試更好的標法，
// 加井字號是為了隔開0#10#0，若不加則變成0100，會導致答案混淆、錯誤。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string key = getKey(strs[i]);
            m[key].push_back(strs[i]);
        }
        
        vector<vector<string>> result;
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
    }
private:
    string getKey(string str) {
        vector<int> count(26);
        for (int j = 0; j < str.size(); j++) {
            count[str[j] - 'a']++;
        }
        
        string key = "";
        for (int i = 0; i < count.size(); i++) {
            key.append(to_string(count[i]) + '#');
        }
        cout << key << endl;
        return key;
    }
};

int main()
{
    vector<string> nums;

    string question;

    int i = 0;

    while(cin >> question)
    {
        if(question == "quit")
            break;

        nums.push_back(question);
    }

    Solution AnswerFunction;

    AnswerFunction.groupAnagrams(nums);
}