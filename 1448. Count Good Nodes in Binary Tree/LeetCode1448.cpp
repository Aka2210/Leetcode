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
    int goodNodes(TreeNode* root) {
        int ans = 0;
        dfs(root, INT32_MIN, &ans);
        return ans;
    }

private:
    void dfs(TreeNode *root, int max, int *ans)
    {
        if(root == NULL)
            return;

        if(root->val >= max)
        {
            (*ans)++;
            dfs(root->left, root->val, ans);
            dfs(root->right, root->val, ans);
        }
        else
        {
            dfs(root->left, max, ans);
            dfs(root->right, max, ans);
        }

        return;
    }
};