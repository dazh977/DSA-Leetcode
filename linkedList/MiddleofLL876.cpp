ListNode* middleNode(ListNode* head) {
        if (head->next == nullptr) return head;
        ListNode* slow = head, * fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
