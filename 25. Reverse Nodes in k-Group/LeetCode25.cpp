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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        
        ListNode* pre = NULL, *curr = head, *calAmount = head;

        int amount = k - 1;

        while(amount > 0)
        {
            head = head->next;
            amount--;
        }

        while(calAmount != NULL)
        {
            ListNode *temp = calAmount->next;
            if(amount == k - 1)
            {
                pair<ListNode*, ListNode*> records = reverse(pre, curr, k);
                if(pre != NULL)
                    pre->next = records.first;
                curr->next = records.second;

                pre = curr;
                curr = records.second;
                amount = 0;
            }
            else
                amount++;

            calAmount = temp;
        }

        return head;
    }

private:
    pair<ListNode*, ListNode*> reverse(ListNode* pre, ListNode* curr, int k)
    {
        for(int i = 0; i < k; i++)
        {
            ListNode* temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }

        return {pre, curr};
    }  
};

int main()
{
    int k;
    cin >> k;
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

    current = AnswerFunction.reverseKGroup(h1, k);

    while(current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
}