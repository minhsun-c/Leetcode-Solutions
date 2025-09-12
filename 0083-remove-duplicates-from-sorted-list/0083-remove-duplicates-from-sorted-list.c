/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *delete(struct ListNode *head, int target) {
    while (head) {
        if (head -> val == target) head = head -> next;
        else return head;
    }
    return NULL;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    int prev = INT_MIN;
    struct ListNode **ptr = &head;
    while (*ptr) {
        if ((*ptr) -> val == prev) {
            (*ptr) = delete(*ptr, prev);
        } else {
            prev = (*ptr) -> val;
            ptr = &((*ptr)->next);
        }
    }
    return head;
}