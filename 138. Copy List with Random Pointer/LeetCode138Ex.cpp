#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<string.h>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodes;
        Node* h = head;
        
        while (h){
            nodes[h] = new Node(h->val);
            h = h->next;
        }
        h = head;
        while (h){
            Node* newNode = nodes[h];
            newNode->next = nodes[h->next];
            newNode->random = nodes[h->random];
            h = h->next;
        }
        return nodes[head];
    }
};

int main()
{
    int val;
    cin >> val;

    Node *h1 = new Node(val);
    Node *current = h1;

    while(cin >> val)
    {
        Node *input = new Node(val);
        current->next = input;
        current = input;
    }

    Solution AnswerFunction;

    current = AnswerFunction.copyRandomList(h1);

    while(current != nullptr)
    {
        cout << current->val << ":" << current->random << " ";
        current = current->next;
    }
}