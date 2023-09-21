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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        Push(root, ans);
        return ans;
    }
private:
    void Push(TreeNode* curr, vector<int>& ans)
    {
        if(curr == nullptr)
            return;
        else
        {
            Push(curr->left, ans);
            ans.push_back(curr->val);
            Push(curr->right, ans);
        }
    }
};