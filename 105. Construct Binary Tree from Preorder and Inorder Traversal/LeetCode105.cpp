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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }

private: 
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index, int Left, int Right) {
        if(Left > Right)
            return NULL;
            
        int split;

        TreeNode* root = new TreeNode(preorder[index]);

        for(int i = Left; i <= Right; i++)
        {
            if(preorder[index] == inorder[i])
            {
                split = i;
                break;
            }
        }
        index++;

        root->left = build(preorder, inorder, index, Left, split - 1);
        root->right = build(preorder, inorder, index, split + 1, Right);

        return root;
    }
};