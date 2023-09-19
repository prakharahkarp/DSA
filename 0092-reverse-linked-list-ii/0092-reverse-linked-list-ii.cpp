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
    
    ListNode* reverseLL(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *curr = head, *prev = nullptr, *next = head->next;
        while(next != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next == nullptr) return head;
        ListNode *curr = head, *partHead = nullptr, *temp = nullptr, *temp2 = nullptr, *temp3 = nullptr;
        int count = 1;
        while(curr != nullptr){
            if(count == left - 1){
                temp2 = curr; //1
            }
            if(count == left){
                partHead = new ListNode(curr->val);
                temp = partHead;
            }
            else if(count > left && count <= right){
                temp->next = new ListNode(curr->val);
                temp = temp->next;
            }
            else if(count == right + 1){
                temp3 = curr; //5
            }
            count++;
            curr = curr->next;
        }
        temp = partHead; //2
        partHead = reverseLL(partHead); //4
        // while(partHead != nullptr){
        //     cout<<partHead->val<<" ";
        //     partHead = partHead->next;
        // }
        // cout<<"\n";
        if(left == 1){
            head = partHead;
        }
        else{
            temp2->next = partHead;
        }
        if(right == count){
            temp->next = nullptr;
        }
        else{
            temp->next = temp3;
        }
        return head;
    }
};

