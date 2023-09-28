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
    int maxPathSum(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
            return root->val;
        int MAX = INT16_MIN;
        return max(MAX, dfs(root, MAX));
    }
    
private:
    int dfs(TreeNode* root, int& MAX)
    {
        if(root == NULL)
            return 0;
        
        int left = dfs(root->left, MAX), right = dfs(root->right, MAX); //32到37其實可以化簡，像EX那樣，剩下的想法就都一樣了。
        int curr = root->val;
        if(left > 0)
            curr += left;
        if(right > 0)
            curr += right;
        MAX = max(MAX, curr);

        return max(max(left, right) + root->val, root->val);
    }
};