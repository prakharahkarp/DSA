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
    ListNode* revLL(ListNode* curr, ListNode* prev){
        if(curr->next == nullptr){
            curr->next = prev;
            return curr;
        }
        ListNode* ans = revLL(curr->next, curr);
        curr->next = prev;
        return ans;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        return revLL(head, nullptr);
    }
};