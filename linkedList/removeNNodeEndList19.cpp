ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        int sz = 0;
        while (cur) {
            cur = cur->next;
            sz++;
        }
        cur = head;
        int dest = sz - n, i = 0;
        if (dest == 0) {
            head = cur->next;
            delete(cur);
            return head;
        }
        
        while (i < dest) {
            prev = cur;
            cur = cur->next;
            i++;
        }
        prev->next = cur->next;
        delete(cur);
        return head;
    }
