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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val)
            return lowestCommonAncestor(root, q, p);

        if(root == NULL)
            return NULL;

        if(root->val >= p->val && root->val <= q->val)
            return root;
        else
        {
            TreeNode *ansLeft = lowestCommonAncestor(root->left, p, q), *ansRight = lowestCommonAncestor(root->right, p, q);
            return ansLeft == NULL ? ansRight : ansLeft;
        }
    }
};