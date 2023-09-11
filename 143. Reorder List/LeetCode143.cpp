#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<string.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> records;

        ListNode* current = head;
        while(current != NULL)
        {
            records.push_back(current);
            current = current->next;
        }

        int counts = records.size() % 2 == 0 ? records.size() / 2 - 1 : records.size() / 2;

        current = head;
        for(int i = 0, n = records.size() - 1; i < counts; i++, n--, current = current->next)
        {
            ListNode* temp = current->next;
            current->next = records[n];
            current = current->next;
            current->next = temp;
        }
        
        if(records.size() % 2 == 0)
        {
            current->next = records[records.size() - 1 - counts];
            current = current->next;
            current->next = NULL;
        }
        else
            current->next = NULL;
    }
};

int main()
{
    int val;
    cin >> val;

    ListNode *h1 = new ListNode(val);
    ListNode *current = h1;

    while(cin >> val)
    {
        ListNode *input = new ListNode(val);
        current->next = input;
        current = input;
    }

    Solution AnswerFunction;

    AnswerFunction.reorderList(h1);
    current = h1;

    while(current != nullptr)
    {
        cout << current->val << endl;
        current = current->next;
    }
}