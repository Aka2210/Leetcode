#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
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
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        dfs(root, &ans);
        return ans;
    }

private:
    int dfs(TreeNode* node, bool *ans)
    {
        if(node != NULL)
        {
            int leftHight = 1 + dfs(node->left, ans), rightHight = 1 + dfs(node->right, ans);
            if(abs(leftHight - rightHight) > 1)
                *ans = false;
            return max(leftHight, rightHight);
        }
        else
            return 0;
    }
};