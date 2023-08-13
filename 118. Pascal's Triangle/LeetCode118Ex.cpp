#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<string.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ret;

        for(int i = 0; i < numRows ; i++){
            vector<int> row(i+1, 1);
            for(int j = 1; j < i ; j++){
                row[j] = ret[i-1][j] + ret[i-1][j-1];
            }
            ret.push_back(row);
        }

        return ret;
    }
};

int main()
{
    int num;

    cin >> num;

    Solution AnswerFunction;

    AnswerFunction.generate(num);
}