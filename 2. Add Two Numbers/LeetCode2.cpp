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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *current1 = l1, *current2 = l2, *ans = new ListNode(), *head = ans, *pre;
        int val = 0;

        while(current1 != NULL || current2 != NULL)
        {
            int sum = val;
            
            sum = current1 != NULL ? sum + current1->val : sum;
            sum = current2 != NULL ? sum + current2->val : sum;
            
            ans->val = sum % 10;
            ans->next = new ListNode();
            pre = ans;
            ans = ans->next;

            val = sum / 10;
            current1 = current1 != NULL ? current1->next : current1;
            current2 = current2 != NULL ? current2->next : current2;
        }

        if(val == 1)
            ans->val = val;
        else
            pre->next = NULL;

        return head;
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
        if(val == -1)
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

    current = AnswerFunction.addTwoNumbers(h1, h2);

    while(current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
}