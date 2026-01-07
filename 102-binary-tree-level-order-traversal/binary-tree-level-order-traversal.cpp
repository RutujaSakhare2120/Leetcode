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
  
    void print(TreeNode *root, int curr, int required,vector<int>&v)
        {
        if (root==NULL)
            return;
       else  if (curr == required)
        {
            v.push_back(root->val);
            return;
        }
       
        print(root->left, curr + 1, required,v);
         print(root->right, curr + 1, required,v);

       
        }

    int levels(TreeNode *root)
        {
        if (!root)
            return 0;
        return 1 + max(levels(root->left) , levels(root->right));
        }
    void levelorder(TreeNode* root,vector<vector<int>>&ans){
        {
        int n = levels(root);
        for (int i = 1; i <= n; i++)
        {   vector<int>v;
            print(root, 1, i,v);
            ans.push_back(v);
        }
        return;
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        levelorder(root,ans);
        return ans;

    }
};