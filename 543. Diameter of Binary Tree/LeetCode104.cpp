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
    int diameterOfBinaryTree(TreeNode* root) {   
        if(root != NULL)
        {
            int left = root->left == NULL ? 0 : DepthJudge(0, root->left), right = root->right == NULL ? 0 : DepthJudge(0, root->right);
            return max(max(left + right, diameterOfBinaryTree(root->right)), diameterOfBinaryTree(root->left));
        }
        return 0;
    }
private:
    int DepthJudge(int Max, TreeNode* node)
    {
        if(node != NULL)
        {
            Max += 1;
            return max(DepthJudge(Max, node->right), DepthJudge(Max, node->left));
        }
        else
            return Max;
    }
};