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
    unordered_map<int,TreeNode*> root;
    set<int> child;
    bool fun(TreeNode* temp,long low,long high){
        if(temp==nullptr){
            return true;
        }
        if(temp->val<=low || temp->val>=high) return false;

        if(root.find(temp->val)!=root.end()){
            if(temp->left || temp->right) return false;
            temp->left=root[temp->val]->left;
            temp->right=root[temp->val]->right;
            root.erase(temp->val);

        }
        return fun(temp->left,low,temp->val)&&fun(temp->right,temp->val,high);
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        
        for(auto it:trees){
            root[it->val]=it;
            if(it->left) child.insert(it->left->val);
            if(it->right) child.insert(it->right->val);
        }
        TreeNode* temp=NULL;
        for(auto it:trees){
            if(child.find(it->val)==child.end()){
                if(temp){
                    return nullptr;
                }
                temp=it;
            }
        }
        if(!temp) return NULL;
        root.erase(temp->val);
        if(!fun(temp,LONG_MIN,LONG_MAX)) return nullptr;
        if(!root.empty()) return NULL;
        return temp;

    }
};