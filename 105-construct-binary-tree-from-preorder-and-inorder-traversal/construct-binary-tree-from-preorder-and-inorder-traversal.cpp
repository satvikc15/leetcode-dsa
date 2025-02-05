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
    TreeNode* buildTreeHelper(vector<int> &preorder, int &preIndex, 
                          int inStart, int inEnd, unordered_map<int, int> &mpp) {
        if (inStart > inEnd) return nullptr;

        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = mpp[rootVal];

        root->left = buildTreeHelper(preorder, preIndex, inStart, inIndex - 1, mpp);
        root->right = buildTreeHelper(preorder, preIndex, inIndex + 1, inEnd, mpp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }

        int preIndex = 0;
        return buildTreeHelper(preorder, preIndex, 0, inorder.size() - 1, mpp);
    }
};