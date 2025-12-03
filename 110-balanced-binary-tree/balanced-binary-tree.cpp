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
    int fun(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int a = fun(root->left);
        int b = fun(root->right);
        if(a==-1||b==-1) return -1;
        return abs(a-b)<=1 ? 1+max(a,b):-1;
    }
    bool isBalanced(TreeNode* root) {
        return fun(root)!=-1;
    }
};