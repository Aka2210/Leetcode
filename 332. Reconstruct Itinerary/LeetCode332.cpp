#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //儲存Edge A->B可以走的次數
        unordered_map<string, int> g;
        //儲存總共有哪些節點
        unordered_set<string> records;
        //儲存所有節點，且排序由字典序小到大
        vector<string> StrOrder;
        //Edge的總數
        int n = tickets.size();
        vector<string> result;

        for(int i = 0; i < n; i++)
        {
            //str用來儲存此邊可走的次數
            string a = tickets[i][0], b = tickets[i][1], str = a + b;
            //如果還沒遇過字串a，推入StrOrder，等等要進行排序
            if(records.find(a) == records.end())
            {
                StrOrder.push_back(a);
                records.insert(a);
            }
            if(records.find(b) == records.end())
            {
                StrOrder.push_back(b);
                records.insert(b);
            }
            //a->b可走次數++
            g[str]++;
        }

        sort(StrOrder.begin(), StrOrder.end());
        result.push_back("JFK");
        //利用dfs推入到達終點所需經過的節點
        dfs(result, n, result[0], g, StrOrder);
        return result;
    }
private:
    bool dfs(vector<string> &result, int edges, string node, unordered_map<string, int> &g, vector<string> &StrOrder)
    {
        if(edges == 0)
            return true;
        
        //StrOrder為字串以字典序小到大排列而成
        for(int i = 0; i < StrOrder.size(); i++)
        {
            string nextNode = node + StrOrder[i];
            if(g[nextNode] == 0)
                continue;
            result.push_back(StrOrder[i]);
            g[nextNode]--;
            if(dfs(result, edges - 1, StrOrder[i], g, StrOrder))
                return true;
            g[nextNode]++;
            result.pop_back();
        }

        return false;
    }
};