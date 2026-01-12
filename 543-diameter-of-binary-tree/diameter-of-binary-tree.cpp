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
    int ans;
    int helper(TreeNode* root){
        if(root==NULL) return 0;
        int leftSide=helper(root->left);
        int rightSide=helper(root->right);
        int myAns=leftSide+rightSide;
        ans=max(ans, myAns);
        return 1+max(leftSide,rightSide);
    }
    int diameterOfBinaryTree(TreeNode* root) {
         ans=0;
          helper(root); 
          return ans;
    }
};