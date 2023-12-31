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
        if (head->next == NULL) {
            return;
        }
        
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != NULL && fast->next != NULL) { //找到list的中點，使slow為中點的下一格
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        
        ListNode* l1 = head; //設置l1為list中第一格到中點
        ListNode* l2 = reverse(slow); //設置l2為list中點後一格到末端，並顛倒過來
        
        merge(l1, l2); //將l1、l2交叉混合。
    }
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr->next;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    void merge(ListNode* l1, ListNode* l2) {
        while (l1 != NULL) {
            ListNode* p1 = l1->next;
            ListNode* p2 = l2->next;
            
            l1->next = l2;
            if (p1 == NULL) {
                break;
            }
            l2->next = p1;
            
            l1 = p1;
            l2 = p2;
        }
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