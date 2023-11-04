#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> records;
        Node* copy;
        if(node)
            copy = new Node(node->val);
        else
            return NULL;
        queue<Node*> qC, q;
        q.push(node);
        qC.push(copy);
        records[node->val] = copy;
        while(!q.empty())
        {
            int count = q.size();
            for(int i = 0; i < count; i++)
            {
                for(int j = 0; j < q.front()->neighbors.size(); j++)
                {
                    int _val = q.front()->neighbors[j]->val;
                    if(records.find(_val) == records.end())
                    {
                        records[_val] = new Node(_val);
                        q.push(q.front()->neighbors[j]);
                        qC.push(records[_val]);
                    }

                    qC.front()->neighbors.push_back(records[_val]);
                }

                q.pop();
                qC.pop();
            }
        }

        return copy;
    }
};