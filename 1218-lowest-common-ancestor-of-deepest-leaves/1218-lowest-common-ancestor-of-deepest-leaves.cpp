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
    int height(TreeNode* root) {
        if (!root) return 0; 
        return 1 + max(height(root->left), height(root->right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if (!root) return nullptr; 
        int lh = height(root->left);
        int rh = height(root->right); 
        if (lh == rh) return root;
        return (lh > rh) ? lcaDeepestLeaves(root->left) : lcaDeepestLeaves(root->right);
    }
};