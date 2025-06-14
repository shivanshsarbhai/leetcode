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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prehead = new ListNode(-1);
        ListNode* curr = prehead;
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;
        while(curr1 && curr2){
            int val1 = curr1->val;
            int val2 = curr2->val;

            if(val1<val2){
                curr->next = curr1;
                curr1 = curr1->next;
            } else {
                curr->next = curr2;
                curr2 = curr2->next;
            }

            curr = curr->next;
        }

        if(!curr1)
            curr->next = curr2;
        
        else
            curr->next = curr1;
        
        return prehead->next;
    }
};