/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *l1 = headA, *l2 = headB;
    while (l1 != l2) {
        if (l1) l1 = l1 -> next;
        else l1 = headB;
        if (l2) l2 = l2 -> next;
        else l2 = headA;
    }
    return l1;
}