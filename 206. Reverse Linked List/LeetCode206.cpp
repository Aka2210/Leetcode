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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        
        while(head != nullptr)
        {
            ListNode *temp = head;
            head = temp->next;
            temp->next = pre;
            pre = temp;
        }

        return pre;
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