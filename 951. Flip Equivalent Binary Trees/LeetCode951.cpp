#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<queue>

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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL)
            return true;

        if(root1 == NULL || root2 == NULL)
            return false;
        
        if(root1->val != root2->val)
            return false;

        if(root1->left != NULL && root2->left != NULL)
        {
            if(root1->left->val != root2->left->val)
                swap(root2->left, root2->right);
        }

        if(root1->left == NULL && root2->left != NULL || root1->left != NULL && root2->left == NULL)
            swap(root2->left, root2->right);

        return flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
    }
};