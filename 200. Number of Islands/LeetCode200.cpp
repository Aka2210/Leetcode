#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        int result = 0;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    q.push(make_pair(i, j));
                    
                    while(!q.empty())
                    {
                        int count = q.size();
                        for(int k = 0; k < count; k++)
                        {
                            if(q.front().first+1 < grid.size() && grid[q.front().first+1][q.front().second] == '1')
                            {
                                grid[q.front().first+1][q.front().second] = '0';
                                q.push(make_pair(q.front().first+1, q.front().second));
                            }

                            if(q.front().first-1 >= 0 && grid[q.front().first-1][q.front().second] == '1')
                            {
                                grid[q.front().first-1][q.front().second] = '0';
                                q.push(make_pair(q.front().first-1, q.front().second));
                            }

                            if(q.front().second+1 < grid[0].size() && grid[q.front().first][q.front().second+1] == '1')
                            {
                                grid[q.front().first][q.front().second+1] = '0';
                                q.push(make_pair(q.front().first, q.front().second+1));
                            }

                            if(q.front().second-1 >= 0 && grid[q.front().first][q.front().second-1] == '1')
                            {
                                grid[q.front().first][q.front().second-1] = '0';
                                q.push(make_pair(q.front().first, q.front().second-1));
                            }

                            q.pop();
                        }
                    }
                    result++;
                }
            }
        }

        return result;
    }
};