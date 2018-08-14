/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/


/*
    Basic idea: space for time.
    Store mapping relationship: [index-pointer mapping] and [pointer-index mapping].
    Thus we can access a new pointer when access an origin pointer.
    Construct this mapping relationship while contstructing the new list.
    Then iterate once to set the random pointers for each node.
    Time complexity is O(n) + O(n) = O(n). Space complexity is O(2*n) = O(n);
*/

/*
    Method 1: using extra space (HashTable), space for time.
    Store mapping relationship: [index-pointer mapping] and [pointer-index mapping].
    Thus we can access a new pointer when access an origin pointer.
    Construct this mapping relationship while contstructing the new list.
    Then iterate once to set the random pointers for each node.
    Time complexity is O(n) + O(n) = O(n). Space complexity is O(2*n) = O(n);
    
    Method 2: without using extra space, associate the original node with its copy node in a single linked list.
    
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // return copyV1(head);
        
        return copyV2(head);
    }
    
    // Method 2: associate the original node with its copy node in a single linked list.
    RandomListNode *copyV2(RandomListNode *head) {
        RandomListNode *origin_head, *new_head, *ptr;
        origin_head = ptr = head;
        if (head == NULL)
            return NULL;
        // 1. make copy of each node, and link them together side-by-side in a single list.
        while (ptr != NULL) {
            RandomListNode *ptr_next = ptr->next;
            ptr->next = new RandomListNode(ptr->label);
            ptr->next->next = ptr_next;
            ptr = ptr_next;
        }
        // 2. assign random pointers for the copy nodes.
        ptr = head;
        while (ptr != NULL) {
            if (ptr->random != NULL) {
                // ptr->random is the origin list's random, ptr->random->next is random in the new list.
                ptr->next->random = ptr->random->next;
            }
            ptr = ptr->next->next;
        }
        // 3. restore the original list, and extract the copy list.
        RandomListNode *new_ptr = head->next;
        ptr = new_ptr->next;
        new_head = new_ptr;
        if (ptr == NULL)  {
            head->next = NULL;
        }
        while (ptr != NULL) {
            new_ptr->next = ptr->next;
            head->next = ptr;
            head = ptr;
            ptr = ptr->next->next;
            new_ptr = new_ptr->next;
        }
        head->next = ptr;
        return new_head;
    }
    
    void printList(RandomListNode *head) {
        while (head != NULL) {
            cout << head->label << ",";
            head = head->next;
        }
        cout << endl;
    }
    
    //  Method 1: using extra space (HashTable), space for time.
    RandomListNode *copyV1(RandomListNode *head) {
        RandomListNode *new_head, *ptr, *temp_new_head, *origin_head;
        if (head == NULL)
            return NULL;
        origin_head = head;
        unordered_map<RandomListNode*, int> origin_ptr_to_int;
        vector<RandomListNode*> new_ptrs;
        int ptr_cnt = 0;
        ptr = new RandomListNode(head->label);
        origin_ptr_to_int[head] = ptr_cnt++;
        new_ptrs.push_back(ptr);
        new_head = ptr;
        head = head->next;
        while (head != NULL) {  // Pay attention to the order of add new element and iterate to next.
            ptr->next = new RandomListNode(head->label);
            origin_ptr_to_int[head] = ptr_cnt++;
            head = head->next;
            ptr = ptr->next;
            new_ptrs.push_back(ptr);
        }
        temp_new_head = new_head;
        // Assign random pointer value.
        while (origin_head != NULL) {
            if (origin_head->random == NULL) {
                temp_new_head->random = NULL;
            } else {
                int ptr_num = origin_ptr_to_int[origin_head->random];
                temp_new_head->random = new_ptrs[ptr_num];
            }
            temp_new_head = temp_new_head->next;
            origin_head = origin_head->next;
        }
        return new_head;
    }
}; 