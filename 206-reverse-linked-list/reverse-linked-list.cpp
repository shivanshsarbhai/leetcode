/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* recursive(ListNode* head){
        if(!head || !head->next)
            return head;

        ListNode* next = head->next;
        head->next = NULL;
        ListNode* newHead = recursive(next);
        ListNode* curr = newHead;
        while(curr->next)
            curr = curr->next;
        curr->next = head;
        return newHead;
    }

    ListNode* reverseList(ListNode* head) {
        return recursive(head);
    }
};