#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        dfs(root, &ans);

        for(int i = 0; i < ans.size() - 1; i++)
        {
            if(ans[i] > ans[i + 1])
                return false;
        }

        return true;
    }

private:
    void dfs(TreeNode *node, vector<int> *ans)
    {
        if(node == NULL)
            return;
        dfs(node->left, ans);
        (*ans).push_back(node->val);
        dfs(node->right, ans);
    }
};