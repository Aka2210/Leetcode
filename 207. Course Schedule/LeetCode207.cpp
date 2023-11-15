#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string.h>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        bool visited[numCourses];
        unordered_map<int, vector<int>> records;
        for(int i = 0; i < numCourses; i++)
            visited[i] = false;

        for(int i = 0; i < prerequisites.size(); i++)
            records[prerequisites[i][0]].push_back(prerequisites[i][1]); //建立graphs各節點的關聯

        while(!records.empty())
        {
            if(!dfs((*records.begin()).first, records, visited)) //進行dfs偵測
                return false;
        }

        return true;
    }
private:
    bool dfs(int val, unordered_map<int, vector<int>> &records, bool* visited)
    {
        if(visited[val] && records.find(val) != records.end()) //代表造成circle，直接回傳false
            return false;
        else
        {
            visited[val] = true; //將node改為true代表已經訪問過此節點
            for(int i = records[val].size() - 1; i >= 0; i--)
            {
                if(!dfs(records[val][i], records, visited))
                    return false;
                records[val].pop_back(); //將搜索過的分支刪除
            }
            records.erase(val); //將此節點刪除，避免之後的dfs又跑一次造成效率下降。
        }

        return true;
    }
};