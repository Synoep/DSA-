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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        if(root==nullptr) return { };
        vector<vector<int>> ans;
        vector<int>w;
        while(!q.empty()){
            vector<int>v;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* a=q.front();
                q.pop();
                if(v.size()==n-1) w.push_back(a->val);
                if(a->left!=nullptr) q.push(a->left);
                if(a->right!=nullptr) q.push(a->right);
                v.push_back(a->val);
            }
            ans.push_back(v);
        }
        return w;
    }
};