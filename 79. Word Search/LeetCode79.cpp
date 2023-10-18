#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
            {
                if(dfs(i, j, board, word, 0))
                    return true;
            }

        return false;
    }

private:
    bool dfs(int i, int j, vector<vector<char>>& board, string& word, int currIndex)
    {
        if(currIndex == word.size())
            return true;
        else if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '*')
            return false;
        
        if(word[currIndex] == board[i][j])
        {
            char tempC = board[i][j];
            board[i][j] = '*';
            bool R = dfs(i + 1, j, board, word, currIndex+1) || 
                    dfs(i - 1, j, board, word, currIndex+1) || 
                    dfs(i, j + 1, board, word, currIndex+1) || 
                    dfs(i, j - 1, board, word, currIndex+1);
            board[i][j] = tempC;
            return R;
        }
        else
            return false;
    }
};