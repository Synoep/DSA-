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
    int ans=0;
    auto dfs(TreeNode * root,int curr){
       if(root==NULL){
        return;
       }
       ans=max(ans,curr);
       dfs(root->left,curr+1);
       dfs(root->right,curr+1);
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
       dfs(root,1);
       return ans;
    }
};