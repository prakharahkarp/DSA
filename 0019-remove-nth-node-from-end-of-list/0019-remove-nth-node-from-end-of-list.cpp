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
        if(head == nullptr || head->next == nullptr){
            delete head;
            return nullptr;
        }
        int countNodes = 0;
        ListNode *curr = head, *temp = nullptr, *prev = head;
//         curr is used to traverse the LL, temp temporarily stores the node to be deleted and prev stores the nodes just before the node to be deleted
        while(curr != nullptr){
            if(countNodes > n){
                prev = prev->next;
            }
            countNodes++;
            curr = curr->next;
        }
        
        if(n == countNodes){
            temp = head;
            head = head->next;
        }
        else{
            temp = prev->next;
            prev->next = prev->next->next;
        }
        delete temp;
        return head;
    }
};