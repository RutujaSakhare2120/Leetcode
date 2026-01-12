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

    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(level(root->left) ,level(root->right) );
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int diameter=level(root->left)+level(root->right);
    
        int leftSide=diameterOfBinaryTree(root->left);
        int rightSide=diameterOfBinaryTree(root->right);
        
        return max(diameter,max(leftSide,rightSide));
        
    }
};