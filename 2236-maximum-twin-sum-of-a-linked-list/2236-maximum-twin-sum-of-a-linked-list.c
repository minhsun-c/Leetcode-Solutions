/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getmid(struct ListNode *head) {
    struct ListNode *slow = head, *fast = head;
    while (fast && fast -> next && fast -> next -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    fast = slow -> next;
    slow -> next = NULL;
    return fast;
}

struct ListNode *reverse(struct ListNode *head) {
    struct ListNode *prev = NULL, *cur = head, *next;
    while (cur) {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

int pairSum(struct ListNode* head) {
    struct ListNode *head2 = reverse(getmid(head));
    int max = 0;
    int sum;
    while (head && head2) {
        sum = head -> val + head2 -> val;
        if (sum > max) max = sum;
        head = head -> next;
        head2 = head2 -> next;
    }
    return max;
}