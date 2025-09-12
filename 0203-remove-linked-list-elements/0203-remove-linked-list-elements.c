/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode **ptr = &head;
    while (*ptr) {
        if ((*ptr)->val == val) {
            *ptr = (*ptr)->next;
        } else {
            ptr = &((*ptr) -> next);
        }
    }
    return head;
}