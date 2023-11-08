#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;

        for(int i = 0; i < heights.size(); i++)
        {
            for(int j = 0; j < heights[i].size(); j++)
            {
                bool TopLeft = false;
                bool RightDown = false;

                DFS(heights, i, j, TopLeft, RightDown);
                if(TopLeft && RightDown)
                    result.push_back({i, j});
            }
        }
        
        return result;
    }

private:
    void DFS(vector<vector<int>>& heights, int i, int j, bool &TopLeft, bool &RightDown)
    {
        if(TopLeft && RightDown)
            return;

        int temp = heights[i][j];

        if(i <= 0 || j <= 0)
            TopLeft = true;
        
        if(i >= heights.size() - 1 || j >= heights[0].size() - 1)
            RightDown = true;
        
        if(i - 1 >= 0 && heights[i][j] >= heights[i - 1][j])
        {
            heights[i][j] = INT32_MAX;
            DFS(heights, i - 1, j, TopLeft, RightDown);
            heights[i][j] = temp;
        }
        
        if(i + 1 < heights.size() && heights[i][j] >= heights[i + 1][j])
        {
            heights[i][j] = INT32_MAX;
            DFS(heights, i + 1, j, TopLeft, RightDown);
            heights[i][j] = temp;
        }

        if(j - 1 >= 0 && heights[i][j] >= heights[i][j - 1])
        {
            heights[i][j] = INT32_MAX;
            DFS(heights, i, j - 1, TopLeft, RightDown);
            heights[i][j] = temp;
        }

        if(j + 1 < heights[0].size() && heights[i][j] >= heights[i][j + 1])
        {
            heights[i][j] = INT32_MAX;
            DFS(heights, i, j + 1, TopLeft, RightDown);
            heights[i][j] = temp;
        }
    }
};