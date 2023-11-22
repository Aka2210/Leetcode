#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

//題目重點因為每個節點進入次數必=離開次數，因此若不符合該條件則，此節點必為
//起點或終點，若該點非JFK(題目要求起點)，則將該點作為終點，若所有節點進入與
//離開次數皆相同，則以JFK當作終點(因為代表最終會回歸)。
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        //儲存Edge A->B可以走的次數
        unordered_map<string, int> g;
        //儲存所有節點進出次數
        unordered_map<string, pair<int, int>> records;
        //儲存所有節點字典序
        vector<string> StrOrder;
        //Edge的總數
        int n = tickets.size();
        //設定起點及終點
        string beginNode = "JFK", endNode = "JFK";
        vector<string> result;

        for(int i = 0; i < n; i++)
        {
            //a、b用來在records內儲存進、出的次數，str用來儲存此邊可走的次數
            string a = tickets[i][0], b = tickets[i][1], str = a + b;
            //如果還沒遇過字串a，推入StrOrder，等等要進行排序
            if(records[a].first == 0 && records[a].second == 0)
                StrOrder.push_back(a);
            if(records[b].first == 0 && records[b].second == 0)
                StrOrder.push_back(b);
            //a->b可走次數++
            g[str]++;
            //b點進入次數++
            records[b].first++;
            //a點離開次數++
            records[a].second++;
        }

        sort(StrOrder.begin(), StrOrder.end());

        for(auto it = records.begin(); it != records.end(); it++)
        {
            string str = it->first;
            int gap = abs(it->second.first - it->second.second);
            //若有進出數不同且不為JFK的點則代表該點為終點，儲存後離開迴圈
            //因為一定有答案，所以gap只能是0或1(>1會導致在edges尚未完全遍歷時，出不去或回不來節點)
            if(gap == 1 && str != "JFK")
            {
                endNode = str;
                break;
            }
        }
        
        result.push_back(beginNode);
        //利用dfs推入到達終點所需經過的節點
        dfs(result, n, beginNode, endNode, g, StrOrder);
        return result;
    }
private:
    bool dfs(vector<string> &result, int edges, string node, string &end, unordered_map<string, int> &g, vector<string> &StrOrder)
    {
        if(edges == 0 && node == end)
            return true;
        
        //StrOrder為字串以字典序小到大排列而成
        for(int i = 0; i < StrOrder.size(); i++)
        {
            string nextNode = node + StrOrder[i];
            if(g[nextNode] == 0)
                continue;
            result.push_back(StrOrder[i]);
            g[nextNode]--;
            if(dfs(result, edges - 1, StrOrder[i], end, g, StrOrder))
                return true;
            g[nextNode]++;
            result.pop_back();
        }

        return false;
    }
};