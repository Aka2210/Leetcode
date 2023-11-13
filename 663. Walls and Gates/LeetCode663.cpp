#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        int m = rooms.size(), n = rooms[0].size(); //儲存矩陣長寬
        queue<pair<int ,int>> q;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(rooms[i][j] == 0)
                    q.push(make_pair(i, j)); //將大門存入隊列
            }
        }

        int distance = 1;
        while(!q.empty()) //持續偵測是否還有未偵測四方是否是房間的格子，若有則進入迴圈。
        {
            int count = q.size(); //計算所有與gate距離為distance的房間數量
            for(int i = 0; i < count; i++) //偵錯所有與gate距離為distance的房間的四方是否也為房間，若是則推入隊列，等待下一層distance偵測
            {
                int a = q.front().first, b = q.front().second;
                if(a + 1 < m && rooms[a + 1][b] == INT32_MAX) //前者判斷避免overflow，後者判斷是否為尚未計算與大門距離的空房。
                {
                    q.push(make_pair(a + 1, b));
                    rooms[a + 1][b] = distance;
                }
                
                if(a - 1 >= 0 && rooms[a - 1][b] == INT32_MAX)
                {
                    q.push(make_pair(a - 1, b));
                    rooms[a - 1][b] = distance;
                }

                if(b + 1 < n && rooms[a][b + 1] == INT32_MAX)
                {
                    q.push(make_pair(a, b + 1));
                    rooms[a][b + 1] = distance;
                }

                if(b - 1 >= 0 && rooms[a][b - 1] == INT32_MAX)
                {
                    q.push(make_pair(a, b - 1));
                    rooms[a][b - 1] = distance;
                }
                q.pop();
            }
            distance++; //判斷完後因為所有與大門距離為distance的房間都已被推出隊列，隊列內僅剩與大門距離為distance+1的房間，因此distance++。
        }
    }
};