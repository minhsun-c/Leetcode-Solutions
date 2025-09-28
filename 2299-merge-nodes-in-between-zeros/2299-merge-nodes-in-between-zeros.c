/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeNodes(struct ListNode* head) {
    struct ListNode *head2 = head->next, **ptr = &head2;
    int cnt = 0;
    while (*ptr) {
        if ((*ptr)->val == 0) {
            (*ptr)->val = cnt;
            cnt = 0;
            ptr = &((*ptr)->next);
        } else {
            cnt += (*ptr)->val;
            *ptr = (*ptr)->next;
        }
    }
    return head2;
}