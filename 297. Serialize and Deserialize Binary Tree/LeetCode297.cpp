#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)
            return "#N";

        queue<TreeNode*> q;
        q.push(root);
        string ans = to_string(root->val);

        while(!q.empty())
        {
            int count = q.size();

            for(int i = 0; i < count; i++)
            {
                if(q.front()->left != NULL)
                {
                    ans += "#" + to_string(q.front()->left->val);
                    q.push(q.front()->left);
                }
                else
                    ans += "#N";

                if(q.front()->right != NULL)
                {
                    ans += "#" + to_string(q.front()->right->val);
                    q.push(q.front()->right);
                }
                else
                    ans += "#N";
                
                q.pop();
            }
        }

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "#N")
            return NULL;

        vector<string> rootVal;
        stringstream ss(data);
        string token;

        while (getline(ss, token, '#')) 
            rootVal.push_back(token);

        TreeNode* root = new TreeNode(stoi(rootVal[0]));
        TreeNode* ans = root;

        queue<TreeNode*> q;
        q.push(root);
        int index = 1;

        while(!q.empty())
        {
            int count = q.size();

            for(int i = 0; i < count; i++)
            {
                q.front()->left = rootVal[index][0] != 'N' ? new TreeNode(stoi(rootVal[index])) : NULL;
                index++;
                q.front()->right = rootVal[index][0] != 'N' ? new TreeNode(stoi(rootVal[index])) : NULL;
                index++;

                if(q.front()->left != NULL)
                    q.push(q.front()->left);

                if(q.front()->right != NULL)
                    q.push(q.front()->right);
                
                q.pop();
            }
        }

        return ans;
    }
};