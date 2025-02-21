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
class FindElements {
public:
    unordered_map<int,int> mpp;
    void fun(TreeNode* root){
        if(root==nullptr) return;
        if(mpp.size()==0){root->val=0; mpp[0]++;}
        if(root->left) {
            root->left->val=2*root->val+1;
            mpp[root->left->val]++;
        }
        if(root->right){
            root->right->val=2*root->val+2;
            mpp[root->right->val]++;
        }
        fun(root->left);
        fun(root->right);
    }
    FindElements(TreeNode* root) {
        fun(root);
        
    }
    
    bool find(int target) {
        if(mpp.find(target)!=mpp.end()) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */