/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p0 = new ListNode(0);
        // Not directly use head is because when n == total_len, it is more easy to deal with.
        p0->next = head;
        // Fast (p2) and slow (p1) pointer.
        ListNode *p1 = p0, *p2 = p0;
        int i = n;
        while (i > 0) {
            i--;
            p2 = p2->next;
        }
        while (p2->next != NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        ListNode *delete_p = p1->next;
        p1->next = delete_p->next;
        delete delete_p;
        return p0->next;
    }
};
