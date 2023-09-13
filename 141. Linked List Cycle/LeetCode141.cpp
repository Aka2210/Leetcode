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
    bool hasCycle(ListNode *head) {
        if (head == NULL) {
            return false;
        }
        
        ListNode *currentLow = head, *currentFast = head;

        while(currentFast->next != NULL && currentFast->next->next != NULL)
        {
            currentLow = currentLow->next;
            currentFast = currentFast->next->next;

            if(currentLow == currentFast)
                return true;
        }
        return false;
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

    if(AnswerFunction.hasCycle(h1))
        cout << "true";
    else
        cout << "false";
}