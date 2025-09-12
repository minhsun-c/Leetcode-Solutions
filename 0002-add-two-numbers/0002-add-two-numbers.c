/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int sum, cout = 0;
    struct ListNode **p1 = &l1;
    struct ListNode **p2 = &l2;
    while (*p1 && *p2) {
        sum = cout + (*p1)->val + (*p2)->val;
        cout = sum / 10;
        sum = sum % 10;
        (*p1)->val = sum;
        p1 = &((*p1) -> next);
        p2 = &((*p2) -> next);
    }
    if (*p1 == NULL) *p1 = *p2;
    while (*p1) {
        sum = cout + (*p1)->val;
        cout = sum / 10;
        sum = sum % 10;
        (*p1)->val = sum;
        p1 = &((*p1) -> next);
    }
    printf("cout: %d\n", cout);
    if (cout) {
        struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = cout;
        node->next = NULL;
        *p1 = node;
    }
    return l1;
}