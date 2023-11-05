#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int result = 0, MAX = 0;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    q.push(make_pair(i, j));
                    
                    while(!q.empty())
                    {
                        if(q.front().first+1 < grid.size() && grid[q.front().first+1][q.front().second] == 1)
                        {
                            grid[q.front().first+1][q.front().second] = 0;
                            q.push(make_pair(q.front().first+1, q.front().second));
                        }

                        if(q.front().first-1 >= 0 && grid[q.front().first-1][q.front().second] == 1)
                        {
                            grid[q.front().first-1][q.front().second] = 0;
                            q.push(make_pair(q.front().first-1, q.front().second));
                        }

                        if(q.front().second+1 < grid[0].size() && grid[q.front().first][q.front().second+1] == 1)
                        {
                            grid[q.front().first][q.front().second+1] = 0;
                            q.push(make_pair(q.front().first, q.front().second+1));
                        }

                        if(q.front().second-1 >= 0 && grid[q.front().first][q.front().second-1] == 1)
                        {
                            grid[q.front().first][q.front().second-1] = 0;
                            q.push(make_pair(q.front().first, q.front().second-1));
                        }

                        q.pop();
                        MAX++;
                    }

                    result = max(result, MAX);
                    MAX = 0;
                }
            }
        }

        return result;
    }
};