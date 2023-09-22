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
        ListNode* dummy = new ListNode();
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* curr = dummy->next;
        ListNode* temp = NULL;
        
        int count = k;
        
        while (curr != NULL) {
            if (count > 1) {
                temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;

                count--;
            } else {
                prev = curr;
                curr = curr->next;
                count = k;
                
                ListNode* end = curr;
                for (int i = 0; i < k; i++) {
                    if (end == NULL) {
                        return dummy->next;
                    }
                    end = end->next;
                }
            }
        }
        
        return dummy->next;
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