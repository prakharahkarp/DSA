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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = new ListNode();
        ListNode* head = ans;
        ListNode *curr1 = l1, *curr2 = l2;
        while(curr1 != NULL && curr2 != NULL){
            int temp = curr1->val + curr2->val + carry;
            ListNode* tempNode = new ListNode(temp % 10);
            ans->next = tempNode;
            temp /= 10;
            carry = temp;
            curr1 = curr1->next;
            curr2 = curr2->next;
            ans = ans->next;
        }
        while(curr1 != NULL){
            int temp = curr1->val + carry;
            ListNode* tempNode = new ListNode(temp % 10);
            ans->next = tempNode;
            temp /= 10;
            carry = temp;
            curr1 = curr1->next;
            ans = ans->next;
        }
        while(curr2 != NULL){
            int temp = curr2->val + carry;
            ListNode* tempNode = new ListNode(temp % 10);
            ans->next = tempNode;
            temp /= 10;
            carry = temp;
            curr2 = curr2->next;
            ans = ans->next;
        }
        if(carry>0){
            ListNode* tempNode = new ListNode(carry);
            ans->next = tempNode;
        }
        head = head->next;
        return head;
    }
};