/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *getmid(struct ListNode *head) {
    struct ListNode **slow = &head;
    struct ListNode *fast = head;
    while (slow && fast) {
        fast = fast -> next;
        slow = &((*slow) -> next);
        if (fast) {
            fast = fast -> next;
        }
    }
    fast = (*slow);
    *slow = NULL;
    return fast;
}

struct ListNode *reverse(struct ListNode *head) {
    struct ListNode *prev = NULL;
    struct ListNode *cur = head;
    struct ListNode *next;

    while (cur) {
        next = cur -> next;
        cur -> next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

void merge(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode **ptr = &l1;
    struct ListNode *h1 = l1;
    struct ListNode *h2 = l2;
    struct ListNode *temp;
    int op = 1;
    while (h1 || h2) {
        if (op) {
            temp = h1;
            h1 = h1 -> next;
            temp -> next = NULL;
            *ptr = temp;
            ptr = &((*ptr) -> next);
        } else {
            temp = h2;
            h2 = h2 -> next;
            temp -> next = NULL;
            *ptr = temp;
            ptr = &((*ptr) -> next);
        }
        op ^= 1;
    }
}

void trav(struct ListNode *h) {
    while (h) {
        printf("%d -> ", h -> val);
        h = h -> next;
    }
    printf("NULL\n");
}

void reorderList(struct ListNode* head) {
    struct ListNode *head2 = reverse(getmid(head));
    trav(head);
    trav(head2);
    merge(head, head2);
}