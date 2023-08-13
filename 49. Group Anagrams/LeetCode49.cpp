#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cmath>
#include <random>

using namespace std;

// 標字母的方式改一下就可以O(n*k)了。

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> record;
        int index = 0;

        for(int i = 0; i < strs.size(); i++)
        {
            string temp = "";
            vector<int> tempRecord;

            for(int j = 0; j < strs[i].length(); j++)
            {
                tempRecord.push_back(static_cast<int>(strs[i][j]));
            }

            sort(tempRecord.begin(), tempRecord.end());
            
            for(int j = 0; j < tempRecord.size(); j++)
                temp += static_cast<char>(tempRecord[j]);
            
            if(record.find(temp) == record.end())
            {
                record.insert(make_pair(temp, index));
                ans.push_back(vector<string>());
                index++;
            }
        }

        for(int i = 0; i < strs.size(); i++)
        {
            string temp = "";
            vector<int> tempRecord;

            for(int j = 0; j < strs[i].length(); j++)
            {
                tempRecord.push_back(static_cast<int>(strs[i][j]));
            }

            sort(tempRecord.begin(), tempRecord.end());
            
            for(int j = 0; j < tempRecord.size(); j++)
                temp += static_cast<char>(tempRecord[j]);
            
            ans[record.find(temp)->second].push_back(strs[i]);
        }  

        for(vector<string> Arr : ans)
        {
            for(string str : Arr)
                cout << str << " ";
            cout << endl;
        }

        return ans;
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