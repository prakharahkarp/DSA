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
    void mergeLists(ListNode* curr, ListNode* list1, ListNode* list2){
        if(list1 == nullptr){
            curr->next = list2;
            return ;
        } else if(list2 == nullptr){
            curr->next = list1;
            return ;
        } else {
            if(list1->val <= list2->val){
                curr->next = list1;
                list1 = list1->next;
            } else{
                curr->next = list2;
                list2 = list2->next;
            }
            mergeLists(curr->next, list1, list2);
        }
    }
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(-101);
        ListNode* curr = dummyHead;
        mergeLists(curr, list1, list2);
        ListNode* head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};