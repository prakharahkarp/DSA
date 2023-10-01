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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;
        ListNode *even = head->next, *curr = head->next->next, *tempOdd = head, *tempEven = head->next;
        while(curr != nullptr){
            tempOdd->next = curr;
            curr = curr->next;
            tempOdd = tempOdd->next;
            if(curr == nullptr) break;
            tempEven->next = curr;
            tempEven = tempEven->next;
            curr = curr->next;
        }
        tempEven->next = nullptr;
        tempOdd->next = even;
        return head;
    }
};