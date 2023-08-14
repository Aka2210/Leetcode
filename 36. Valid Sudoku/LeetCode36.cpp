#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<string.h>

using namespace std;

// 建表後再逐一判斷，若是可以把判斷寫入第一個雙迴圈內，就可以不用建表了(參考Ex的答案)。

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, int> sRow[9], sColumn[9], sSquare[9];

        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                sRow[i][board[i][j] - '0']++;
                sColumn[j][board[i][j] - '0']++;
                sSquare[i / 3 * 3 + j / 3][board[i][j] - '0']++;
            }
        }

        for(int i = 0; i < 9; i++)
        {
            for(int j = 1; j <= 9; j++)
            {
                if(sRow[i][j] > 1 || sColumn[i][j] > 1 || sSquare[i][j] > 1)
                    return false;
            }
        }

        return true;
    }
};

int main()
{
    vector<vector<char>> board(9);

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            char ch;
            cin >> ch;
            board[i].push_back(ch);
        }
    }

    Solution AnswerFunction;

    if(AnswerFunction.isValidSudoku(board))
        cout << "true";
    else
        cout << "false";
}