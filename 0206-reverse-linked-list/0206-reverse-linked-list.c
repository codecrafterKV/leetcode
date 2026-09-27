/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next = NULL;

    while (curr != NULL) {
        next = curr->next;  // Save next node
        curr->next = prev;  // Reverse current node's pointer
        prev = curr;        // Move prev forward
        curr = next;        // Move curr forward
    }

    return prev; // prev is the new head of the reversed list
}