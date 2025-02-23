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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* nn = new TreeNode(preorder[0]);
        if(preorder.size()==1) return nn;
        unordered_map<int,int> mpp;
        for(int i=0;i<postorder.size();i++){
            mpp[postorder[i]]=i;
        }
        stack<TreeNode*> st;
        st.push(nn);
        for(int i=1;i<preorder.size();i++){
            int t=preorder[i];
            while(!st.empty() && mpp[t]>mpp[st.top()->val]){
                st.pop();
            }
            TreeNode* f=new TreeNode(t);
            if(!st.top()->left) st.top()->left=f;
            else st.top()->right=f;
            st.push(f);
        }
        return nn;
    }
};