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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        return dfs(root, &ans, k);
    }

private:
    int dfs(TreeNode* node, vector<int> *ans, int k)
    {
        if(node == NULL)
            return 0;

        dfs(node->left, ans, k);
        if((*ans).size() != k)
            (*ans).push_back(node->val);
        dfs(node->right, ans, k);
        return (*ans).back();
    }
};