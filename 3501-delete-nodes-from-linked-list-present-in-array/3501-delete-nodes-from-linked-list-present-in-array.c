/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    int hash[100005];
    memset(hash, 0, sizeof(hash));
    for (int i=0; i<numsSize; i++) hash[nums[i]] ++;

    struct ListNode **ptr = &head;
    while (*ptr) {
        int x = (*ptr)->val;
        if (hash[x] > 0) 
            *ptr = (*ptr)->next;
        else
            ptr = &((*ptr)->next);
    }
    return head;
}