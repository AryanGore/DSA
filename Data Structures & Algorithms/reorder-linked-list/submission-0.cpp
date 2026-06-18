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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = slow->next;
        ListNode* prev = nullptr;

        while(temp != nullptr){
            ListNode* nextNode = temp->next;
            temp->next = prev;
            prev = temp;
            temp = nextNode;
        }

        slow->next = nullptr;
        temp = head;

        while(prev!= nullptr && temp != nullptr){
            ListNode* t1 = temp->next;
            ListNode* t2 = prev->next;
            
            temp->next = prev;
            temp = t1;
            prev->next = temp;
            prev = t2;
        }

    }
};
