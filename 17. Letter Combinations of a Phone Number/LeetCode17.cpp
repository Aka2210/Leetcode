#include<iostream>
#include<string>
#include<vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> records;
        records['2'] = "abc";
        records['3'] = "def";
        records['4'] = "ghi";
        records['5'] = "jkl";
        records['6'] = "mno";
        records['7'] = "pqrs";
        records['8'] = "tuv";
        records['9'] = "wxyz";
        string curr = "";
        vector<string> result;
        dfs(0, digits, curr, result, records);
        return result;
    }

private:
    void dfs(int index, string &digits, string &curr, vector<string> &result, unordered_map<char, string> &records)
    {
        if(index == digits.size())
        {
            if(curr != "")
                result.push_back(curr);
            return;
        }

        for(int i = 0; i < records[digits[index]].size(); i++)
        {
            curr.push_back(records[digits[index]][i]);
            dfs(index + 1, digits, curr, result, records);
            curr.pop_back();            
        }
    }
};