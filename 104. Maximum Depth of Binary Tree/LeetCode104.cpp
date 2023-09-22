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
    int maxDepth(TreeNode* root) {   
        return DepthJudge(0, root);
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