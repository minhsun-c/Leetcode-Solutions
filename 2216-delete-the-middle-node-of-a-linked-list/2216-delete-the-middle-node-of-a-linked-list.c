/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    struct ListNode **slow = &head;
    struct ListNode *fast = head;
    while (slow && fast) {
        fast = fast -> next;
        if (fast) {
            fast = fast -> next;
            slow = &((*slow) -> next);
        }
    }
    *slow = (*slow) -> next;
    return head;
}