#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //紀錄每點最短抵達時間(INT_MAX代表無法抵達)
        vector<int> records(n*n, INT_MAX); 
        pq.push({grid[0][0], 0});
        //抵達(0,0)所需時間亦為起始時間
        records[0] = grid[0][0]; 

        while(!pq.empty())
        {
            int ReachTime = pq.top().first, total = pq.top().second, x = total / n, y = total % n;
            pq.pop();

						//當前時間>此點儲存的最短抵達時間，代表前面已經處理過此點的BFS，直接進入下一次BFS
            if(ReachTime > records[total])
                continue;
            else if(total == n * n - 1) //第一次抵達終點即為最短路徑，直接回傳所需時間。
                return ReachTime;

			//對當前位置的相臨位置做檢查，如果利用此位置能比當前更快速抵達臨邊則推入隊列
            if(x + 1 < n)
            {
				//time代表當前節點前往臨邊所需的時間
                int time = max(grid[x+1][y], ReachTime), pos = (x+1) * n + y;
				//檢查是否進入速度更快
                if(records[pos] > time)
                {
                    pq.push({time, pos});
                    records[pos] = time;
                }
            }
            if(x - 1 >= 0)
            {
                int time = max(grid[x-1][y], ReachTime), pos = (x-1) * n + y;
                if(records[pos] > time)
                {
                    pq.push({time, pos});
                    records[pos] = time;
                }
            }
            
            if(y + 1 < n)
            {
                int time = max(grid[x][y+1], ReachTime), pos = x * n + y + 1;
                if(records[pos] > time)
                {
                    pq.push({time, pos});
                    records[pos] = time;
                }
            }
            if(y - 1 >= 0)
            {
                int time = max(grid[x][y-1], ReachTime), pos =  x * n + y - 1;
                if(records[pos] > time)
                {
                    pq.push({time, pos});
                    records[pos] = time;
                }
            }
        }

        return -1;
    }
};