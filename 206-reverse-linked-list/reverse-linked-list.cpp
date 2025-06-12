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

        ListNode* newHead = recursive(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* iterative(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }


    ListNode* reverseList(ListNode* head) {
        // return recursive(head);
        return iterative(head);
    }
};