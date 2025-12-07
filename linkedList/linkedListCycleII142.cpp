ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return nullptr;
        ListNode* slow = head, * fast = head;
        bool hasCycle = false;
        while (fast && fast->next) {
            
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle) return nullptr;
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
            if (slow == fast) return slow;
        }
        return slow;
    }
