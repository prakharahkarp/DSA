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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* curr = head;
        int countNodes = 0, count = 1;
        while(curr != nullptr){
            countNodes++;
            curr = curr->next;
        }
        k = k%countNodes;
        if(k == 0) return head;
        curr = head;
        while(count < countNodes - k){
            count++;
            curr = curr->next;
        }
        ListNode *temp = curr->next, *newHead = curr->next;
        curr->next = nullptr;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = head;
        return newHead;
        
    }
};