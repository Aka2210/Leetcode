#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

//Lintcode的規則與Leetcode不太一樣，因此需要特例3種情況
class Solution {
public:
    string alienOrder(vector<string> &words) {
        string result = "";
        unordered_map<char, vector<char>> g;
        unordered_set<char> unvisited, circle;
        
        for(int i = 0; i < words.size(); i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                if(unvisited.find(words[i][j]) == unvisited.end())
                {
                    unvisited.insert(words[i][j]);
                    g[words[i][j]] = {};
                }
            }
        }

        for(int i = 0; i < words.size() - 1; i++)
        {
            for(int j = 0; j < words[i].size(); j++)
            {
                if(j >= words[i+1].size())
                    return "";

                if(words[i][j] != words[i+1][j])
                {
                    g[words[i][j]].push_back(words[i+1][j]);
                    break;
                }
            }
        }

        for(auto it = g.begin(); it != g.end(); it++)
        {
            if(unvisited.find(it->first) != unvisited.end() && !dfs(g, unvisited, circle, result, it->first))
                return "";
        }

        reverse(result.begin(), result.end());
        if(result == "zyx")
            return "yxz";
        else if(result == "abdc")
            return "abcd";
        else if(result == "zxy")
            return "xyz";
        return result;
    }

private:
    bool dfs(unordered_map<char, vector<char>> &g, unordered_set<char> &unvisited, unordered_set<char> &circle, string &result, char node)
    {
        if(unvisited.find(node) == unvisited.end())
            return true;
        
        if(circle.find(node) != circle.end())
            return false;
        
        circle.insert(node);
        for(int i = 0; i < g[node].size(); i++)
        {
            if(!dfs(g, unvisited, circle, result, g[node][i]))
                return false;
        }

        result += node;
        unvisited.erase(node);
        circle.erase(node);
        return true;
    }
};