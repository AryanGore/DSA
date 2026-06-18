/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* originalHead = head;
        Node* dummy = new Node(-101);
        Node* prev = dummy;

        unordered_map<Node*, Node*>pointerMap;

        while(originalHead){
            Node* newnode = new Node(originalHead->val);
            pointerMap[originalHead] = newnode;
            prev->next = newnode;
            prev = newnode;
            originalHead = originalHead->next;
        }

        originalHead = head;
        prev = dummy->next;

        while(originalHead && prev){
            if(!originalHead->random) prev->random = nullptr;
            else prev->random = pointerMap[originalHead->random];
            originalHead = originalHead->next;
            prev = prev->next;
        }

        Node* newhead = dummy->next;
        delete dummy;

        return newhead;
    }
};
