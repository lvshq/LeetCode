/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* pre_head = new ListNode(0);
        pre_head->next = head;
        ListNode* new_head = NULL;
        ListNode* end = head;
        bool finish = false;
        while (head) {
            // NOT to k! Only k-1 times.
            for (int i = 0; i < k - 1; i++) {
                if (end->next == NULL) {
                    finish = true;
                    break;
                }
                end = end->next;
            }
            if (!new_head) {
                if (finish) {
                    new_head = head;
                } else {
                    new_head = end;
                }
            }
            // Link pre_head to new head and link new end to end_next.
            if (!finish) {
                ListNode* end_next = end->next;
                reverse(head, end_next);
                pre_head->next = end;
                head->next = end_next;
                pre_head = head;
                head = end_next;
                end = head;
            } else {
                break;
            }
            ListNode* test_ptr = new_head;
        }
        return new_head;
    }

    void reverse(ListNode* head, ListNode* end_next) {
        ListNode* p0 = head;
        ListNode* p1 = head;
        ListNode* p2 = p0->next;
        p0->next = NULL;
        while (p2 != end_next) {
            p1 = p2;
            p2 = p2->next;
            p1->next = p0;
            p0 = p1;
        }
    }
};