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
    void fun(TreeNode* root,int curr){
        int v=root->val;
         curr=(curr*2)+v;
        if(!root->left && !root->right){
            ans+=curr;
            curr-=root->val;
            curr/=2;
        }
        if(root->left!=NULL)fun(root->left,curr);
        if(root->right!=NULL) fun(root->right,curr);
        curr-=root->val;
        curr/=2;
    }
    int sumRootToLeaf(TreeNode* root) {
        fun(root,0);
        return ans;
    }
};