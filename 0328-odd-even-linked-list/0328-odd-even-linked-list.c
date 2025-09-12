/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    struct ListNode *cur;
    struct ListNode *l1 = NULL;
    struct ListNode *l2 = NULL;
    struct ListNode **ptr1 = &l1;
    struct ListNode **ptr2 = &l2;
    int op = 1;
    while (head) {
        cur = head;
        head = head -> next;
        cur -> next = NULL;
        if (op) {
            *ptr1 = cur;
            ptr1 = &((*ptr1) -> next);
        } else {
            *ptr2 = cur;
            ptr2 = &((*ptr2) -> next);
        }
        op ^= 1;
        
    }
    *ptr1 = l2;
    return l1;
}