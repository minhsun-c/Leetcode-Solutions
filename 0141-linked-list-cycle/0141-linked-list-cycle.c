/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow, *fast;
    slow = head;
    fast = head;
    while (slow && fast) {
        slow = slow -> next;
        fast = fast -> next;
        if (fast) fast = fast -> next;
        else return false;
        if (slow && fast && slow == fast) return true;
    }
    return false;
}