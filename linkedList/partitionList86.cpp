/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode* small = new ListNode(INT_MIN);
        ListNode* big = new ListNode(INT_MAX);
        ListNode* p = head, *curSmall = small, *curBig = big;
        while (p) {
            if (p->val < x) {
                curSmall->next = p;
                curSmall = curSmall->next;
                p = p->next;
                curSmall->next = nullptr;
            } else {
                curBig->next = p;
                curBig = curBig->next;
                p = p->next;
                curBig->next = nullptr;
            }
            
        }

        curSmall->next = big->next;
        return small->next;
    }
};

/*if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(INT_MAX);
        ListNode* cur = dummy;
        ListNode* ptr = head;
        while (ptr) {
            if (ptr->val < x) {
                cur->next = ptr;
                cur = cur->next;
            }
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            if (ptr->val >= x) {
                cur->next = ptr;
                cur = cur->next;
            }
            ptr = ptr->next;
        }

        return dummy->next;*/
