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
    bool hasCycle(ListNode* head) {
        if(head == nullptr) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;


        while(slow != nullptr && slow->next != nullptr && fast->next != nullptr && fast->next->next != nullptr){
            if(slow->val == fast->val) return true;
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};
