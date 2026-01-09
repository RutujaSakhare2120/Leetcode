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
     
    int levels(TreeNode* root){
        if(!root) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return 0;
        int lefthelper=levels(root->left);
        int righthelper=levels(root->right);

        if(lefthelper==righthelper) return root;
        else if(lefthelper>righthelper) return lcaDeepestLeaves(root->left);
        else return lcaDeepestLeaves(root->right);
        
    }
};