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
        Node *current = head, *pre = NULL, *headChange;
        unordered_map<Node*, Node*> records;

        if(head == NULL)
            return NULL;

        while(current != NULL)
        {
            records[current] = new Node(current->val);
            if(pre != NULL)
                records[pre]->next = records[current];
            else
                headChange = records[current];
            pre = current;
            current = current->next;
        }

        Node *currentInit = head;
        current = headChange;

        for(;current != NULL; current = current->next, currentInit = currentInit->next)
        {
            if(currentInit->random != NULL)
                current->random = records[currentInit->random];
            else
                current->random = NULL;
        }

        return headChange;
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