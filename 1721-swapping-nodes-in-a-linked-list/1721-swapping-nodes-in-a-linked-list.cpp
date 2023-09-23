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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *curr = head, *first = head, *second = head;
        int countNodes = 0;
        while(curr != nullptr){
            if(countNodes == k - 1){
                first = curr;
            }
            if(countNodes >= k){
                second = second->next;
            }
            countNodes++;
            curr = curr->next;
        }
        int temp = first->val;
        first->val = second->val;
        second->val = temp;
        return head;
    }
};