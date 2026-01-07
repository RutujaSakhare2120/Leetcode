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
   long long maxproduct = 0;

   const int mod = 1e9 + 7;

    int totalSum(TreeNode* root){
        if(root==NULL) return 0;
        return  root->val+totalSum(root->left)+totalSum(root->right);

    }
    int helper(TreeNode* root,int TotalSum){
        if(root==NULL) return 0;
       int lst= helper(root->left,TotalSum);
       int rst= helper(root->right,TotalSum);

       int sumSubtree=lst+rst+root->val;
      long long Product = 1LL * (TotalSum - sumSubtree) * sumSubtree;

        maxproduct=max(maxproduct,Product);

        return sumSubtree;


    }
    int maxProduct(TreeNode* root) {
        int TotalSum=totalSum(root);
        helper(root,TotalSum);
       

        return maxproduct%mod;
        
    }
};