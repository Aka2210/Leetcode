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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        OrderTraversl(root, &ans, 0);
        return ans;
    }

private:
    TreeNode* OrderTraversl(TreeNode *node, vector<vector<int>> *ans, int index)
    {
        if(node == NULL)
            return NULL;
        else if(ans->size() <= index)
            (*ans).push_back({node->val});
        else
            (*ans)[index].push_back(node->val);

        OrderTraversl(node->left, ans, index + 1);
        OrderTraversl(node->right, ans, index + 1);
        return NULL;
    }
};