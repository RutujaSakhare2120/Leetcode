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
      unordered_map<int,int>mp;
    int maxD=1;
    void levels(TreeNode* root , int d){
         if(!root) return ;
         maxD=max(maxD , d);
         mp[root->val]=d;
         levels(root->left , d+1);
         levels(root->right , d+1);
    }
    TreeNode* LCA(TreeNode* root){
        if(!root || mp[root->val]==maxD) return root;

        TreeNode* leftSide=LCA(root->left);
        TreeNode* rightSide=LCA(root->right);

        if(leftSide && rightSide ) return root;
        return  rightSide?rightSide:leftSide;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
         levels(root,1);

         return LCA(root);
    }
};