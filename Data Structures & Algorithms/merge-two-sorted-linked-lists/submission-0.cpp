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
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while(l1 != nullptr && l2 != nullptr){
            if(l1->val == l2->val){
                curr->next = new ListNode(l1->val);
                curr = curr->next;
                curr->next = new ListNode(l2->val);
                curr = curr->next;
                l1 = l1->next;
                l2 = l2->next;
            }else if(l1->val < l2->val){
                ListNode* newnode = new ListNode(l1->val);
                curr->next = newnode;
                curr = curr->next;
                l1 = l1->next;
            }else{
                ListNode* newnode = new ListNode(l2->val);
                curr->next = newnode;
                curr = curr->next;
                l2 = l2->next;
            }
        }

        if(l1 != nullptr){
            while(l1 != nullptr){
                ListNode* newnode = new ListNode(l1->val);
                curr->next = newnode;
                curr = curr->next;
                l1 = l1->next;
            }
        }

        if(l2 != nullptr){
            while(l2 != nullptr){
                ListNode* newnode = new ListNode(l2->val);
                curr->next = newnode;
                curr = curr->next;
                l2 = l2->next;
            }
        }

        ListNode* newhead = dummy->next;
        return newhead;
    }
};
