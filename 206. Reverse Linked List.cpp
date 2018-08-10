/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?
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
    ListNode* reverseList(ListNode* head) {
        // Method 1: iterative version. More Easy and intuitive!
        // return iterativeReverse(head);
        
        // Method 2: recursive version.
        return recursiveReverse(head);
    }

    // Method 1: iterative version. More Easy and intuitive !
    ListNode* iterativeReverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        // Use 3 pointers to finish the task.
        ListNode* p1 = NULL;
        ListNode* p2 = head;
        ListNode* p3 = head->next;
        while (p2 != NULL) {
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            if (p3 == NULL)
                break;
            p3 = p3->next;
        }
        return p1;
    }
    

    // Method 2: recursive version.
    ListNode* recursiveReverse(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        // Pre-process the last node in reversed list.
        ListNode* head_next = head->next;
        head->next = NULL;
        return reverseList(head, head_next);
    }
    ListNode* reverseList(ListNode* n1, ListNode* n2) {
        if (n2 == NULL) {  // The end of recursion
            return n1;
        }
        ListNode* n2_next = n2->next;
        if (n1 && n2) {
            // Do reverse in every recursion step.
            n2->next = n1;
            return reverseList(n2, n2_next);
        }
    }
};