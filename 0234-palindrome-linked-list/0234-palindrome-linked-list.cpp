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
private:
    ListNode* reverse(ListNode *prev, ListNode *curr){
        ListNode *next = curr->next;
        while(curr != nullptr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        
        ListNode *slow = head, *fast = head, *prev = nullptr;
        int flag = 0;
        
//         finding the middle node of the LL
        while(fast != nullptr && fast->next != nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // when the nodes are odd, the fast pointer points to the last node and when they are even and otherwise it points to null
//         in case of odd number of nodes, the middle node has no one to compare with, so we can just ignore it
        if(fast != nullptr){
            slow = slow->next;
        }
        
//         reversing the later half of the LL, so that we can compare the ith node from the beginning and end easily
//         we have made the next of the reversed head of second half of linked list as nullptr, so it has been disconnected from the rest of the LL. This helps us in easy traversal of the LL and gives us a stopping condition
        ListNode *revHead = reverse(nullptr, slow);
        ListNode* curr = head, *revCurr = revHead;
        
        // comparing the ith node from the beginning and end
        while(revCurr != nullptr){
            if(curr->val != revCurr->val){
                flag = 1;
                break;
            }
            revCurr = revCurr->next;
            curr = curr->next;
        }
        
//         restoring the original form of the Linked List
        revHead = reverse(nullptr, revHead);
        prev->next = revHead;
        
        return flag == 0;
    }
};