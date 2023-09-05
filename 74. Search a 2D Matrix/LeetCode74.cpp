#include<iostream>
#include<string>
#include<vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0; i < matrix.size(); i++)
        {
            if(matrix[i][matrix[i].size() - 1] > target)
            {
                int L = 0, R = matrix[i].size() - 1;
                
                while(L <= R)
                {
                    int mid = L + (R - L) / 2;

                    if(matrix[i][mid] < target)
                        L = mid + 1;
                    else if(matrix[i][mid] > target)
                        R = mid - 1;
                    else
                        return true;
                }
            }
            else if(matrix[i][matrix[i].size() - 1] == target)
                return true;
        }

        return false;
    }
};

int main()
{
    vector<vector<int>> nums;

    int question, target;

    cin >> target;

    string space = "";

    while(space != "L")
    {
        nums.push_back({});
        while(cin >> question)
            nums.back().push_back(question);
        cin >> space;
    }

    Solution AnswerFunction;

    if(AnswerFunction.searchMatrix(nums, target))
        cout << "true";
    else
        cout << "false";
}