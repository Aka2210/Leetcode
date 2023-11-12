#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) //遍歷最上方及最下方，並做dfs，檢查是否有O與牆壁相鄰
        {
            dfs(board, i, 0);
            dfs(board, i, board[0].size() - 1);
        }

        for(int j = 0; j < board[0].size(); j++) //遍歷最左方及最右方，並做dfs，檢查是否有O與牆壁相鄰
        {
            dfs(board, 0, j);
            dfs(board, board.size() - 1, j);
        }

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == 'O') //將被包圍的O改為X
                    board[i][j] = 'X';
                else if(board[i][j] == '#') //將沒有被包圍的O保留
                    board[i][j] = 'O';
            }
        }
        return;
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j)
    {
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;

        if(board[i][j] == 'O') //檢查是否為O，若是則進行擴散並改為#表示此為無法被包圍的O(因為鄰近牆壁)
        {
            board[i][j] = '#';
            dfs(board, i + 1, j);
            dfs(board, i - 1, j);
            dfs(board, i, j + 1);
            dfs(board, i, j - 1);
        }

        return;
    }
};