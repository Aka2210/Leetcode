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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head, *pre = NULL;
        vector<pair<ListNode*, ListNode*>> records;

        while(current != NULL)
        {
            records.push_back({pre, current->next});
            pre = current;
            current = current->next;
        }

        if(records[records.size() - n].first != NULL)
            records[records.size() - n].first->next = records[records.size() - n].second;
        else
            return head->next;
        
        return head;
    }
};

int main()
{
    int n;
    cin >> n;
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

    current = AnswerFunction.removeNthFromEnd(h1, n);

    while(current != nullptr)
    {
        cout << current->val << endl;
        current = current->next;
    }
}