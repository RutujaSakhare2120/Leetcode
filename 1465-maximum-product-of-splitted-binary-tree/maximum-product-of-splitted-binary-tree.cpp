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
    long long maxproduct=0;
    const int mod=1e9+7;
     int totalSum=0;
     
    int TotalSum(TreeNode* root){
        if(!root) return 0;
        return root->val+TotalSum(root->left)+TotalSum(root->right);
    }
    long long helper(TreeNode* root){
         if(!root) return 0;
         //used postOrder Traversal
        int lst= helper(root->left);
        int rst=helper(root->right);

         int subtreeSum=lst+rst+root->val;
         long long product=1LL* (totalSum-subtreeSum)*subtreeSum;

         maxproduct=max(maxproduct, product);
         return subtreeSum;
    }
    int maxProduct(TreeNode* root) {
        totalSum=TotalSum(root);
        helper(root);
        return maxproduct%mod;
    }
};