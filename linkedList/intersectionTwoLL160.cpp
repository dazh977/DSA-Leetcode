ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> seen;
        ListNode* head = headA;
        while (head) {
            seen.insert(head);
            head = head->next;
        }
        head = headB;
        while (head) {
            if (seen.count(head)) return head;
            head = head->next;
        }
        return nullptr;
    }
