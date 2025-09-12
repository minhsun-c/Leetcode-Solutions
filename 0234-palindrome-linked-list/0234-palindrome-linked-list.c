/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode **half(struct ListNode *head) {
    struct ListNode **slow = &head, *fast = head;
    while (*slow && fast) {
        slow = &((*slow) -> next);
        fast = fast -> next;
        if (fast) fast = fast -> next;
    }
    return slow;
}

struct ListNode *rev(struct ListNode *head) {
    struct ListNode *prev = NULL, *cur = head, *next;
    while (cur) {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    struct ListNode **midp = half(head);
    struct ListNode *mid = *midp;
    *midp = NULL;
    struct ListNode *head2 = rev(mid);
    while (head && head2) {
        if (head->val != head2->val) return false;
        head = head -> next;
        head2 = head2 -> next;
    }
    return true;
}