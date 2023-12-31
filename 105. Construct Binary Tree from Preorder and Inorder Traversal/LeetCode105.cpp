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
        return dfs(preorder, inorder, index, 0, inorder.size() - 1);
    }

private:
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int& index, int Left, int Right)
    {
        if(Left > Right)
            return NULL;

        TreeNode* root = new TreeNode(preorder[index]);

        int split = Left;
        for(; split <= Right; split++)
        {
            if(preorder[index] == inorder[split])
                break;
        }

        index++;
        root->left = dfs(preorder, inorder, index, Left, split - 1);
        root->right = dfs(preorder, inorder, index, split + 1, Right);

        return root;
    }
};