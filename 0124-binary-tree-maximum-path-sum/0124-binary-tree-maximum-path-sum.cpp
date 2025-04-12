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
    int path(TreeNode* root, int &maxi){
        if(!root) return 0;
         
        int l =max(0,path(root->left,maxi));
        int r=max(0,path(root->right,maxi));
        maxi=max(maxi,l+r+root->val);
        return root->val +max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        path(root,maxi);
        return maxi;
    }
};