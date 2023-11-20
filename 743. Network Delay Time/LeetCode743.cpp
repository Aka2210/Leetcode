#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> g[n + 1];
        for(int i = 0; i < times.size(); i++)
            g[times[i][0]].push_back({times[i][2], times[i][1]});

        //利用pq使得較前面的時間先運算
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        //儲存最快拜訪的時間
        vector<int> visited(n+1, INT_MAX);
        visited[k] = 0;

        while(!pq.empty())
        {
            int nowTime = pq.top().first, nowNode = pq.top().second;
            //pq需要先推出，否則若最後才推出，遇到push的時間為最小時，因為pq為min heap，會導致推出top值錯誤。
            pq.pop();
            //若已經有更快的路徑則pop此路徑後前往下一個。
            if(visited[nowNode] < nowTime) 
                continue;

            for(int i = 0; i < g[nowNode].size(); i++)
            {
                if(visited[g[nowNode][i].second] > nowTime + g[nowNode][i].first)
                {
                    visited[g[nowNode][i].second] = nowTime + g[nowNode][i].first;
                    pq.push({visited[g[nowNode][i].second], g[nowNode][i].second});
                }
            }
        }

        int result = 0;
        for(int i = 1; i <= n; i++)
        {
            if(visited[i] == INT_MAX)
                return -1;
            else
                result = max(result, visited[i]);
        }

        return result;
    }
};
