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
        if(head == nullptr) return head;
        
        Node *curr = head, *temp = nullptr;
//         creating and linking nodes from old list and their respective shallow copies
        while(curr != nullptr){
            temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = curr->next->next;
        }
//         creating random pointers for new list
        curr = head;
        while(curr != nullptr){
            if(curr->random != nullptr){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
//         seperating the two lists
        Node *newHead = head->next;
        temp = newHead, curr = head;
        
        curr->next = curr->next->next;
        curr = curr->next;
        while(curr != nullptr){
            temp->next = curr->next;
            curr->next = curr->next->next;
            curr = curr->next;
            temp = temp->next;
        }
        
        return newHead;
    }
};