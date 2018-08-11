/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*
    Use [Fast and Slow pointer], if they encounter, then there must be a cycle.
*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode* h1 = head->next;
        bool has_cycle = false;
        while (h1 && h1->next) {
            head = head->next;
            h1 = h1->next->next;
            if (head == h1)
                return true;
        }
        return has_cycle;        
    }
};