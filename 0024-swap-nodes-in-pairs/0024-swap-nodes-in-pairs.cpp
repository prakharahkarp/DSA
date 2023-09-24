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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *curr = head, *temp = head->next, *newHead = head->next, *prev = nullptr;
        curr->next = curr->next->next;
        temp->next = curr;
        prev = curr;
        curr = curr->next;
        while(curr != nullptr && curr->next != nullptr){
            temp = curr->next;
            prev->next = temp;
            curr->next = curr->next->next;
            temp->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return newHead;
    }
};
