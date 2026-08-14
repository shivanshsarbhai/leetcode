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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {
        ListNode* prehead = new ListNode(-1);
        ListNode* curr = prehead;

        while(head1 && head2){
            if(head1->val < head2->val){
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }

            curr = curr->next;
        }

        if(head2)
            curr->next = head2;
        
        else
            curr->next = head1;
            
        return prehead->next;
    }
};