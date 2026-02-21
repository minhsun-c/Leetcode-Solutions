/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverse(struct ListNode *head)
{
    struct ListNode *prev = NULL, *cur = head, *next;
    while (cur) {
        next = cur -> next;
        cur -> next = prev;
        prev = cur; 
        cur = next;
    }
    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) 
{
    struct ListNode *real_head;
    struct ListNode *prev = NULL, *h = head, *t = NULL, *next;
    while (h) {
        t = h;
        for (int cnt = 1; cnt < k; cnt ++) {
            if (t == NULL) return real_head;
            else t = t->next;
        }
        if (t) {
            next = t -> next;
            t->next = NULL;
        } else {
            return real_head;
        }
        if (prev)
            prev -> next = reverse(h);
        else 
            real_head = reverse(h);
        h->next = next;
        prev = h;
        h = next;
    }
    return real_head;
}

struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head -> next == NULL) return head;
    return reverseKGroup(head, 2);
}