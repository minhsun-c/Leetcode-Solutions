/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode *slow, *fast;
    slow = fast = head;
    while (slow && fast) {
        fast = fast -> next;
        if (fast) {
            fast = fast -> next;
            slow = slow -> next;
        }
    }
    return slow;
}