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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* n1 = l1;
        ListNode* n2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        int carry = 0;

        while(n1 || n2 || carry){
            int sum = carry;
            if(n1){
                sum += n1->val;
                n1 = n1->next;
            }

            if(n2){
                sum += n2->val;
                n2 = n2->next;
            }

            carry = sum / 10;
            temp->next = new ListNode(sum%10);
            temp = temp->next;

        }
        ListNode* newhead = dummy->next;
        return newhead;
    }
};
