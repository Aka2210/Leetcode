#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

//dijkstra's algorithm
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> edges[n];
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src, 0});
        vector<vector<int>> cost(n, vector<int>(k + 2, INT_MAX));

        //初始化path
        for(int i = 0; i < flights.size(); i++)
            edges[flights[i][0]].push_back({flights[i][2], flights[i][1]});

        while(!pq.empty())
        {
            int fee = pq.top()[0], source = pq.top()[1],  stop = pq.top()[2];
            pq.pop();

            //第一次遇到dst的花費必為最小，直接回傳
            if(source == dst)
                return fee;

            //若當前路徑走到此點的花費>相同stop數走到此點的花費時，直接continue，因為代表前面算過了(priority_queue會先算fee較小的路徑)
            if(cost[source][stop] < fee)
                continue;

            for(int j = 0; j < edges[source].size(); j++)
            {
                //檢查經過stop個節點後到達此點的最小花費，若比先前紀錄的小則取代並推入當前節點。
                if((stop < k || edges[source][j].second == dst) && cost[edges[source][j].second][stop + 1] > fee + edges[source][j].first)
                {
                    cost[edges[source][j].second][stop + 1] = fee + edges[source][j].first;
                    pq.push({cost[edges[source][j].second][stop + 1], edges[source][j].second, stop + 1});
                }
            }
        }
        
        return -1;
    }
};