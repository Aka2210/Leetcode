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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL)
            return false;
            
        if(Same(root, subRoot))
            return true;
        else
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool Same(TreeNode* node, TreeNode* subNode)
    {
        if(subNode == NULL && node == NULL)
            return true;
        
        if (node == NULL || subNode == NULL)
            return false;

        if(node->val != subNode->val)
            return false;

        return Same(node->left, subNode->left) && Same(node->right, subNode->right);
    }
};