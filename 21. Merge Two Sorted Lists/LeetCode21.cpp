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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *currentL1 = list1, *currentL2 = list2, *ans, *ansHead;

        if(currentL1 == NULL && currentL2 == NULL)
            return NULL;
        else if(currentL1 == NULL)
            return currentL2;
        else if(currentL2 == NULL)
            return currentL1;

        if(currentL1->val > currentL2->val)
        {
            currentL2 = list1;
            currentL1 = list2;
        }

        ans = currentL1;
        ansHead = ans;
        currentL1 = currentL1->next;

        while(currentL1 != NULL && currentL2 != NULL)
        {
            
            if(currentL1->val <= currentL2->val)
            {
                ans->next = currentL1;
                currentL1 = currentL1->next;
                ans = ans->next;
            }
            else
            {
                ans->next = currentL2;
                currentL2 = currentL2->next;
                ans = ans->next;
            }
        }

        if(currentL1 == NULL)
            ans->next = currentL2;
        else
            ans->next = currentL1;
        return ansHead;
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
        if(val == -101)
            break;
        ListNode *input = new ListNode(val);
        current->next = input;
        current = input;
    }

    cin >> val;

    ListNode *h2 = new ListNode(val);
    current = h2;

    while(cin >> val)
    {
        ListNode *input = new ListNode(val);
        current->next = input;
        current = input;
    }

    Solution AnswerFunction;

    ListNode *head = AnswerFunction.mergeTwoLists(h1, h2);
    current = head;

    while(current != nullptr)
    {
        cout << current->val << endl;
        current = current->next;
    }
}