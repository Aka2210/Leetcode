#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string.h>

using namespace std;

//Prim演算法做最小生成樹
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int edges = 0;
        bool visited[n];
        int minEdges[n], CurrNode = 0;

        //設定當前無可前往節點且無節點被拜訪
        for(int i = 0; i < n; i++)
        {
            visited[i] = false;
            minEdges[i] = INT_MAX;
        }

        //欲從points[0]開始，設前往該節點的花費為0(最小邊)
        minEdges[0] = 0;

        //當前總花費為0
        int result = 0;
        while(edges < n)
        {
            int MinEdge = INT_MAX, currPointX = points[CurrNode][0], currPointY = points[CurrNode][1];

            //選擇一個當前可走且花費最小的Edge(當前最小邊)為path，進入其他節點(一開始會抓到最小邊設置為0的節點)。
            for(int i = 0; i < n; i++)
            {
                if(!visited[i] && minEdges[i] < MinEdge)
                {
                    MinEdge = minEdges[i];
                    CurrNode = i;
                }
            }

            //將當前節點設為已拜訪，並將此最小邊加入總花費中。
            visited[CurrNode] = true;
            result += MinEdge;
            edges++;
            
            //偵測新節點通往其他節點的花費
            for(int i = 0; i < n; i++)
            {
                int cost = abs(points[CurrNode][0] - points[i][0]) + abs(points[CurrNode][1] - points[i][1]);
                //若尚未拜訪的邊從此節點前往會比從前面其他點前往的花費還少，則將最小花費設為此節點前往的花費
                if (!visited[i] && minEdges[i] > cost) {
                    minEdges[i] = cost;
                }
            }
        }

        return result;
    }
};