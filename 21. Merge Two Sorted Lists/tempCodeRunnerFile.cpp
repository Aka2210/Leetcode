ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *currentL1 = list1, *currentL2 = list2, *ans, *ansHead;

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