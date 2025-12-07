bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* slow = head, * fast = head;
        
        while (fast && fast->next) {
            if (slow == fast) return true;
            fast = fast->next->next;
            slow = slow->next;
            
        }
        return false;
    }
