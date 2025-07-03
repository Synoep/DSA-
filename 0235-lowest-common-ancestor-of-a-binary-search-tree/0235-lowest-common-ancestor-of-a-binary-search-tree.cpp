/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(root==nullptr||root==p||root==q) return  root;
        // TreeNode* left=lowestCommonAncestor(root->left,p,q);
        // TreeNode* right=lowestCommonAncestor(root->right,p,q);
        // if(left==nullptr) return right;
        // else if(right==nullptr) return left;
        // else return root;
        if(root==nullptr) return root;
        int cur=root->val;
        if(cur<p->val&&cur<q->val) return lowestCommonAncestor(root->right,p,q);
        else if(cur>p->val&&cur>q->val) return lowestCommonAncestor(root->left,p,q);
        return root;
    }
};