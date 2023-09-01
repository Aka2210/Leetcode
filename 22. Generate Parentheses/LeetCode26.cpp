#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        
        string str = "";

        generate(n, 0, 0, str, ans);

        return ans;
    }

private:
    void generate(int n, int open, int close, string str, vector<string>& ans)
    {
        if(open == n && close == n)
        {
            ans.push_back(str);
            return;
        }

        if(open > close && open < n)
        {
            generate(n, open + 1, close, str + '(', ans);
            generate(n, open, close + 1, str + ')', ans);
        }
        else if(open > close)
            generate(n, open, close + 1, str + ')', ans);
        else if(open < n)
            generate(n, open + 1, close, str + '(', ans);
    }
};

int main()
{
    int num;

    cin >> num;

    Solution AnswerFunction;
    
    for(string str : AnswerFunction.generateParenthesis(num))
        cout << str << ",";
}