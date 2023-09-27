#include<iostream>
#include<math.h>
#include<vector>
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
    int sumNumbers(TreeNode* root) {
        vector<string> ans;
        dfs(root, "", ans);

        long result = 0;
        for(int i = 0; i < ans.size(); i++)
            result += stoi(ans[i]);
        
        return result;
    }
private:
    void dfs(TreeNode* root,string curr, vector<string>& ans)
    {
        if(root == NULL)
            ans.push_back(curr);
        else
        {
            curr += to_string(root->val);
            if(root->left == NULL && root->right != NULL || root->left == root->right)
                dfs(root->right, curr, ans);
            else if(root->right == NULL && root->left != NULL)
                dfs(root->left, curr, ans);
            else
            {
                dfs(root->right, curr, ans);
                dfs(root->left, curr, ans);
            }
        }

        return;
    }
};