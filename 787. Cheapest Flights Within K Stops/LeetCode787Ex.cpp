#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

//Bellman-ford Algorithm
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> cost(k+2, vector<int>(n, INT_MAX));
        cost[0][src] = 0;
        int result = INT_MAX;

        for(int i = 1; i <= k+1; i++)
        {
            for(int j = 0; j < flights.size(); j++)
            {
                cost[i][flights[j][1]] = min(cost[i][flights[j][1]], cost[i - 1][flights[j][0]] + flights[j][2]);
                if(flights[j][1] == dst)
                    result = min(result, cost[flights]);
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};