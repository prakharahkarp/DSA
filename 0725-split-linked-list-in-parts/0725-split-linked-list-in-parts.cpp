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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);
        ListNode *curr = head, *temp;
        int countNodes = 0;
        while(curr != NULL){
            countNodes++;
            curr = curr->next;
        }
        curr = head;
        int groupSize, rem = countNodes, remGroups = k, ind = 0;
        while(rem != 0){
            int count = 0;
            ans[ind++] = curr;
            groupSize = ceil((double)rem / remGroups);
            while(count < groupSize-1){
                count++;
                curr = curr->next;
            }
            temp = curr->next;
            curr->next = NULL;
            curr = temp;
            rem -= groupSize;
            remGroups--;
        }
        return ans;
    }
};