/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *half(struct ListNode *head) {
    struct ListNode **slow = &head, *fast = head;
    while (*slow && fast) {
        slow = &((*slow) -> next);
        fast = fast -> next;
        if (fast) fast = fast -> next;
    }
    struct ListNode *ret = *slow;
    *slow = NULL;
    return ret;
}

struct ListNode* merge(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode *head;
    struct ListNode **ptr = &head;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            *ptr = list1;
            list1 = list1 -> next;
        } else {
            *ptr = list2;
            list2 = list2 -> next;
        }
        ptr = &((*ptr)->next);
    }
    if (list1) *ptr = list1;
    if (list2) *ptr = list2;
    return head;
}

struct ListNode* sortList(struct ListNode* head) {
    if (!head || head -> next == NULL) return head;
    struct ListNode *mid = half(head);
    head = sortList(head);
    mid = sortList(mid);
    return merge(head, mid);
}