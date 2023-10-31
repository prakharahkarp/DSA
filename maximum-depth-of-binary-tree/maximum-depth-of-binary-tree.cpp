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
public:
    int findDepth(TreeNode* root, int depth){
        if(root == nullptr) return depth;
        
        int leftDepth = findDepth(root->left, depth + 1);
        int rightDepth = findDepth(root->right, depth + 1);
        
        return max(leftDepth, rightDepth);
    }
    
    int maxDepth(TreeNode* root) {
        return findDepth(root, 0);
    }
};