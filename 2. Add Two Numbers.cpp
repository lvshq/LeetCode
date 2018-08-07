/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l0 = NULL;
        ListNode *sum_pointer = NULL;
        int carry_num = 0;
        while (l1 != NULL || l2 != NULL || carry_num != 0) {
            int current_sum = 0;
            if (l1 != NULL && l2 != NULL) {
                current_sum = l1->val + l2->val + carry_num;
            } else if (l2 != NULL) {
                current_sum = l2->val + carry_num;
            } else if (l1 != NULL) {
                current_sum = l1->val + carry_num;
            } else {
                current_sum = carry_num;
            }
            ListNode *new_node = NULL;
            if (current_sum < 10) {
                new_node = new ListNode(current_sum);
                carry_num = 0;
            } else {
                new_node = new ListNode(current_sum % 10);
                carry_num = 1;
            }
            if (l0 != NULL) {
                l0->next = new_node;
                l0 = l0->next;
            } else {
                l0 = new_node;
                sum_pointer = l0;
            }
            if (l1 != NULL) {
                l1 = l1->next;
            }
            if (l2 != NULL) {
                l2 = l2->next;
            }
        }
        return sum_pointer;
    }
};