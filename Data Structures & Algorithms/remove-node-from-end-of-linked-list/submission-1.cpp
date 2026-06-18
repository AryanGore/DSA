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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return NULL;
        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr){
            count++;
            temp=temp->next;
        }

        //if(count == 1) return nullptr;

        int reqLen = count - n;
        if(reqLen == 0){
            ListNode* newhead = head->next;
            delete head;
            return newhead;
        }


        int idx = 0;
        ListNode* prev = nullptr;
        temp = head;
        while(idx < reqLen){
            prev = temp;
            temp = temp->next;
            idx++;
        }

        prev->next = temp->next;

        delete temp;
        return head;
    }
};
