/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int preIndex = 0, postIndex = 0;
    public:
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[preIndex++]);

        if (root->val != postorder[postIndex]) {
            root->left = constructFromPrePost(preorder, postorder);
        }
        if (root->val != postorder[postIndex]) {
            root->right = constructFromPrePost(preorder, postorder);
        }
        postIndex++;
        
        return root;
    }
};
