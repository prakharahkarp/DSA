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
        Node *dummyNode = new Node(0);
        Node *temp = head, *curr = dummyNode;
        unordered_map<Node*, Node*> rand_mapping;
        
        while(temp != nullptr){
            curr->next = new Node(temp->val);
            rand_mapping[temp] = curr->next;
            curr = curr->next;
            temp = temp->next;
        }
        
        temp = head, curr = dummyNode->next;
        while(temp != nullptr){
            if(temp->random != nullptr){
                curr->random = rand_mapping[temp->random];
            }
            curr = curr->next;
            temp = temp->next;
        }
        
        temp = dummyNode;
        dummyNode = dummyNode->next;
        delete temp;
        
        return dummyNode;
    }
};