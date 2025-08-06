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
    ListNode* findPreMid(ListNode* head){
        ListNode* prehead = new ListNode(-1);
        prehead->next = head;
        ListNode* slow = prehead;
        ListNode* fast = prehead;

        while(fast && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next || !(head->next)->next)
            return ;

        ListNode* preMid = findPreMid(head);
        ListNode* mid = preMid->next;
        preMid->next = NULL;
        ListNode* head2 = reverse(mid);
        ListNode* head1 = head;

        ListNode* prehead = new ListNode(-1);
        ListNode* curr = prehead;

        while(head1 && head2){
            curr->next = head1;
            head1 = head1->next;
            curr = curr->next;
        
            curr->next = head2;
            head2 = head2->next;
            curr = curr->next;
        }

        if(head2)
            curr->next = head2;
    }
};