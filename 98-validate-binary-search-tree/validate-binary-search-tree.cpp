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
    long long maxVal(TreeNode* root){
        if(root==NULL) return LLONG_MIN;
        return max((long long)(root->val) , max(maxVal(root->left) , maxVal(root->right)));


    }
    long long minVal(TreeNode* root){
        if(root==NULL) return LLONG_MAX;
        return min((long long )(root->val) , min(minVal(root->left) , minVal(root->right)));


    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL)) return true;
       else  if((long long)(root->val) <= maxVal(root->left)) return  false;
        else  if((long long)(root->val) >= minVal(root->right)) return false;
        return isValidBST(root->left) && isValidBST(root->right);
        
    }
};