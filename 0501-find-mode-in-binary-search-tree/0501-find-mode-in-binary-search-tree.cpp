/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    unordered_map<int, int> freq;
public:
    void findFreq(TreeNode* root, int& maxFreq){
        if(root == nullptr) return ;
        freq[root->val]++;
        maxFreq = max(maxFreq, freq[root->val]);
        findFreq(root->left, maxFreq);
        findFreq(root->right, maxFreq);
    }
    
    vector<int> findMode(TreeNode* root) {
        int maxFreq = 0;
        findFreq(root, maxFreq);
        vector<int> modes;
        for(auto it : freq){
            if(it.second == maxFreq) modes.push_back(it.first);
        }
        return modes;
    }
};