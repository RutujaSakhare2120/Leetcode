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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
      if(!root) return NULL;

      int leftSubTree=levels(root->left);
      int rightSubTree=levels(root->right);

      if(leftSubTree==rightSubTree) return root;
      else if (leftSubTree>rightSubTree) return subtreeWithAllDeepest(root->left);
      else return subtreeWithAllDeepest(root->right);
        
    }
};