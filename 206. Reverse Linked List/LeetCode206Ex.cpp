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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

int main()
{
    int val;
    cin >> val;

    ListNode *h = new ListNode(val);
    ListNode *first = h;

    while(cin >> val)
    {
        ListNode *input = new ListNode(val);
        h->next = input;
        h = input;
    }

    Solution AnswerFunction;

    ListNode *head = AnswerFunction.reverseList(first);

    while(head != nullptr)
    {
        cout << head->val << endl;
        head = head->next;
    }
}