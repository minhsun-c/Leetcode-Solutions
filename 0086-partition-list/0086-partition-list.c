/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode *head1 = NULL, *head2 = NULL, *temp;
    struct ListNode **ptr1 = &head1, **ptr2 = &head2;

    while (head) {
        temp = head;
        head = head -> next;
        temp -> next = NULL;
        if (temp -> val < x) {
            *ptr1 = temp;
            ptr1 = &((*ptr1)->next);
        } else {
            *ptr2 = temp;
            ptr2 = &((*ptr2)->next);
        }
    }
    *ptr1 = head2;
    return head1;
}