#include<iostream>
#include<math.h>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> currCombine;
        vector<vector<string>> result;
        dfs(0, currCombine, s, result);
        return result;
    }

private:
    void dfs(int start, vector<string>& currCombine, string& s, vector<vector<string>>& result)
    {
        if(start == s.size())
            result.push_back(currCombine);
        
        string curr = "";

        for(int i = start; i < s.size(); i++)
        {
            curr += s[i];
            if(IsPalindrome(curr))
            {
                currCombine.push_back(curr);
                dfs(i + 1, currCombine, s, result);
                currCombine.pop_back();
            }
        }
    }

    bool IsPalindrome(string s)
    {
        for(int i = 0; i < s.size() / 2 + 1; i++)
        {
            if(s[i] != s[s.size() - i - 1])
                return false;
        }

        return true;
    } 
};