#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        bool col[n], row[n], LeftToRight[2 * n - 1], RightToLeft[2 * n - 1];
        int ans = 0;
        vector<vector<string>> result;
        vector<string> curr(n);

        for(int i = 0; i < n * n; i++)
            curr[i / n].push_back('.');

        for(int i = 0; i < n; i++)
        {
            col[i] = false;
            row[i] = false;
        }

        for(int i = 0; i < 2 * n - 1; i++)
        {
            LeftToRight[i] = false;
            RightToLeft[i] = false;
        }
         
        dfs(col, row, LeftToRight, RightToLeft, result, curr, n, 0, ans);
        return result;
    }

private:
    void dfs(bool col[], bool row[], bool LeftToRight[], bool RightToLeft[], vector<vector<string>> &result, vector<string> &curr, int n, int start, int &ans)
    {
        for(int i = start; i < n * n; i++)
        {
            int x = i / n, y = i % n;
            if(!row[x] && !col[y] && !LeftToRight[x + y] && !RightToLeft[x + n - 1- y])
            {
                row[x] = true;
                col[y] = true;
                LeftToRight[x+y] = true;
                RightToLeft[x+n-1-y] = true;
                curr[x][y] = 'Q';
                ans++;
                dfs(col, row, LeftToRight, RightToLeft, result, curr, n, i + 1, ans);
                ans--;
                curr[x][y] = '.';
                row[x] = false;
                col[y] = false;
                LeftToRight[x+y] = false;
                RightToLeft[x+n-1-y] = false;
            }
        }

        if(ans == n)
            result.push_back(curr);
    }
};