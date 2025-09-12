/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *insert(struct ListNode *sorted, struct ListNode *target) {
    struct ListNode **ptr = &sorted;
    struct ListNode *next;
    while (*ptr) {
        if (target -> val < (*ptr) -> val) {
            next = (*ptr);
            *ptr = target;
            target -> next = next;
            return sorted;
        }
        ptr = &((*ptr)->next);
    }
    *ptr = target;
    return sorted;
}


struct ListNode* insertionSortList(struct ListNode* head) {
    struct ListNode *sorted = NULL;
    struct ListNode *target;
    while (head) {
        target = head;
        head = head -> next;
        target->next = NULL;
        sorted = insert(sorted, target);
    } 
    return sorted;
}