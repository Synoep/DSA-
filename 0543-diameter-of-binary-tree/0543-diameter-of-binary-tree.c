/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int f(struct TreeNode* root, int *d){
    if(!root) return 0;
    int l=f(root->left,d);
    int r=f(root->right,d);
    if(*d<l+r) *d=l+r;
    int maxVal;
    if (l > r) {
       maxVal = l;
}   else {
    maxVal = r;
}
return 1 + maxVal;

}

int diameterOfBinaryTree(struct TreeNode* root) {
    int d=0;
    f(root,&d);
    return d;
}