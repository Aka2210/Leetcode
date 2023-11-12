#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int result = -1, FreshOrange = 0; //因為一開始就有的腐爛橘子不可以當作一回合計算，因此result必須設為-1作為校正(在第一次BFS時被校正為0)。
        queue<pair<int, int>> q; //用來做BFS的隊列

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 2) //儲存腐爛橘子的位置
                    q.push(make_pair(i, j));
                else if(grid[i][j] == 1) //計算普通橘子的數量
                    FreshOrange++;
            }
        }

        if(FreshOrange == 0) //如果普通橘子為0則代表所需回合為0，直接return
            return 0;

        while(!q.empty()) //檢查是否還有新腐爛的橘子需要進行下回合的擴散
        {
           int count = q.size(); //儲存需進行擴散的橘子數量
           for(int i = 0; i < count; i++)
           {
            int a = q.front().first, b = q.front().second;
               if(a+ 1 <  grid.size() && grid[a + 1][b] == 1)
               {
                    FreshOrange--; //普通橘子變腐爛後要改變剩餘數量
                    grid[a + 1][b] = 2;
                    q.push(make_pair(a + 1, b)); //推入新腐爛的橘子(用以進行下回合的BFS)
               }

               if(a - 1 >= 0 && grid[a - 1][b] == 1)
               {
                    FreshOrange--;
                    grid[a - 1][b] = 2;
                    q.push(make_pair(a - 1, b));
               }

               if(b + 1 <  grid[0].size() && grid[a][b  + 1] == 1)
               {
                    FreshOrange--;
                    grid[a][b + 1] = 2;
                    q.push(make_pair(a, b + 1));
               }

               if(b - 1 >=  0 && grid[a][b - 1] == 1)
               {
                    FreshOrange--;
                    grid[a][b - 1] = 2;
                    q.push(make_pair(a, b - 1));
               }

               q.pop();
           }
           result++; //所需回合數增加
        }

        return FreshOrange == 0 ? result : -1; //如果普通橘子皆腐爛則輸出回合數，否則輸出-1
    }
};