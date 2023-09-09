/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(ListNode* curr){
        int count = 0;
        while(curr != NULL){
            count++;
            curr = curr->next;
        }
        return count;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currA = headA, *currB = headB;
        int countA = countNodes(headA);
        int countB = countNodes(headB);
        while(countA > countB){
            currA = currA->next;
            countA--;
        }
        while(countB > countA){
            currB = currB->next;
            countB--;
        }
        ListNode *intersectionNode = nullptr;
        while(currA != NULL && currB != NULL){
            if(currA == currB){
                intersectionNode = currA;
                break;
            }
            currA = currA->next;
            currB = currB->next;
        }
        cout<<countA<<" "<<countB<<"\n";
        return intersectionNode;
    }
};