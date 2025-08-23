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
    unordered_map<int,TreeNode*> roots;
    unordered_set<int> child;
    bool dfs(TreeNode* root,long low,long high){
        if(root==NULL){
            return true;
        }
        if (!(low < root->val && root->val < high)) return false;
        
           
            if(roots.find(root->val)!=roots.end()){
                root->left=roots[root->val]->left;
                root->right=roots[root->val]->right;
                roots.erase(root->val);  
            }
                return dfs(root->left, low, root->val) && dfs(root->right, root->val, high);
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        for(auto it:trees){
            roots[it->val]=it;
            if(it->left) child.insert(it->left->val);
            if(it->right) child.insert(it->right->val);
        }
        TreeNode* root=NULL;
        for(auto it:trees){
            if(child.find(it->val)==child.end()){   
                if(root) return nullptr;  
                root=it;
            }
        }
        if(!root) return nullptr;
        roots.erase(root->val);
         if (!dfs(root, LONG_MIN, LONG_MAX)) return nullptr;
         if (!roots.empty()) return nullptr;

        return root;
    }
};