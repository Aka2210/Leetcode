#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

//Kruskal
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int root[n], height[n];
        for(int i = 0; i < n; i++)
        {
            root[i] = i;
            height[i] = 0;
            for(int j = i; j < n; j++)
            {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                int scoure = i, dict = j;
                pq.push({cost, scoure, dict});
            }
        }
        
        int cost = 0, pqSize = pq.size(), edge = 0;
        while(edge != n - 1)
        {
            int CurrCost = pq.top()[0], scoure = pq.top()[1], dict = pq.top()[2]; 
            if(Union(scoure, dict, root, height))
            {
                cost += CurrCost;
                edge++;
            }
            pq.pop();
        }

        return cost;
    }
private:
    int Find(int val, int* root)
    {
        if(root[val] != val)
            root[val] = Find(root[val], root);
        return root[val];
    }

    bool Union(int a, int b, int* root, int* height)
    {
        a = Find(a, root);
        b = Find(b, root);
        if(a == b)
            return false;
        
        if(height[a] > height[b])
            root[b] = a;
        else if(height[a] < height[b])
            root[a] = b;
        else
        {
            root[b] = a;
            height[a]++;
        }

        return true;
    }
};