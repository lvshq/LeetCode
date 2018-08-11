/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6
*/


/*
    Good problem, deserves attention. I used 3 methods here.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Method 1 (Approach 2 in Solution, Compare every k nodes):
        // Time complexity O(N*k). k is len(lists), there are N nodes in the final linked list.
        // 316 ms, beats 9.12 %
        // return mergeKListsV1(lists);
        
        // Method 2 (Approach 3 Priority Queue):
        // Time complexity O(N*log(k)). k is len(lists), there are N nodes in the final linked list.
        // 16 ms, beats 99.73%
        // return mergeKListsV2(lists);
        
        // Method 3 (Approach 5 Merge with Divide And Conquer)
        // Time complexity O(N*log(k)). k is len(lists), there are N nodes in the final linked list.
        // 16 ms, beats 99.73%
        return mergeKListsV3(lists);
    }
    
    // =========================================================
    // Method 3
    ListNode* mergeKListsV3(vector<ListNode*>& lists) {
        int len = lists.size();
        if (len == 0)
            return NULL;
        int interval = 1;
        // If the element number is odd, then last merge will be lists[0] and lists[len-1]
        // So interval should be [0, len) instead of [0, len / 2].
        while (interval < len) {
            for (int i = 0; i + interval < len; i += interval * 2) {
                lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        if (l1 == NULL) {
            return l2;
        } else if (l2 == NULL) {
            return l1;
        } else if (l1->val < l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        ListNode* result = head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        if (l1)
            head->next = l1;
        else if (l2)
            head->next = l2;
        else
            head->next = NULL;
        return result;
    }

    // =========================================================
    // Method 2
    typedef pair<int, ListNode*> NODE;
    
    /*
    template<
        class T,
        class Container = std::vector<T>, 
        class Compare = std::less<typename Container::value_type>
    > class priority_queue;
    */
    // PAY ATTENTION to how to overload 'less' which will be used in priority_queue.
    class myLess {
        public:
            bool operator() (NODE n1, NODE n2) {
                return n1.first > n2.first;
            }
    };
    
    ListNode* mergeKListsV2(vector<ListNode*>& lists) {
        ListNode* result = NULL;
        ListNode* head = result;
        int len = lists.size();
        // Second parameter is Container, necessary.
        priority_queue<NODE, vector<NODE>, myLess> p_q;

        for (int i = 0; i < len; i++) {
            if (lists[i])
                p_q.push( make_pair(lists[i]->val, lists[i]) );  // Don't use pair(...), use make_pair() instead.
        }
        while (!p_q.empty()) {
            NODE min_ele = p_q.top();
            p_q.pop();
            if (head == NULL) {
                head = min_ele.second;
                result = min_ele.second;
            } else {
                head->next = min_ele.second;
                head = head->next;
            }
            min_ele.second = (min_ele.second)->next;
            if (min_ele.second)
                p_q.push( make_pair(min_ele.second->val, min_ele.second) );
        }
        return result;
    }

    // =========================================================
    // Method 1
    ListNode* mergeKListsV1(vector<ListNode*>& lists) {
        ListNode* result = NULL;
        ListNode* head = result;
        int len = lists.size();
        bool has_ele = true;
        while (has_ele) {  // as long as there are elements, continue to add new elements to result list.
            has_ele = false;
            int min_val = INT_MAX;
            int min_node_index = 0;
            for (int i = 0; i < len; i++) {
                if (lists[i] == NULL)
                    continue;
                has_ele = has_ele || (lists[i] != NULL);
                if (lists[i]->val <= min_val) {
                    min_val = lists[i]->val;
                    min_node_index = i;
                }
            }
            if (has_ele && lists[min_node_index] != NULL) {
                if (head == NULL) {
                    head = lists[min_node_index];
                    result = lists[min_node_index];
                } else {
                    head->next = lists[min_node_index];
                    head = head->next;
                }
                lists[min_node_index] = lists[min_node_index]->next;
            }
        }
        return result;
    }
};