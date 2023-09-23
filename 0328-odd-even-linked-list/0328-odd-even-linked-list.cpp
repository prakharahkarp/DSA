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
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *odd = head, *even = head->next, *curr = head->next->next, *temp = curr, *temp2 = head->next;
        while(curr != nullptr){
            temp = curr;
            curr = curr->next;
            odd->next = temp;
            odd = odd->next;
            if(curr == nullptr) break;
            temp = curr;
            curr = curr->next;
            even->next = temp;
            even = even->next;
        }
        even->next = nullptr;
        odd->next = temp2;
        return head;
    }
};