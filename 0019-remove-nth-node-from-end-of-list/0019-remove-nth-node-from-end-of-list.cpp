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
        ListNode *curr = head, *temp = nullptr;
        while(curr != nullptr){
            countNodes++;
            curr = curr->next;
        }
        if(n == countNodes){
            temp = head;
            head = head->next;
            delete temp;
            return  head;
        }
        curr = head;
        int count = 0;
        while(count < countNodes - n - 1){
            count++;
            curr = curr->next;
        }
        temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return head;
    }
};