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
    TreeNode* recoverFromPreorder(string traversal) {
        stack<TreeNode*> st;
        int n = traversal.size();

        for (int i = 0; i < n; ) {
            int count = 0;
            while (i < n && traversal[i] == '-') {
                count++;
                i++;
            }

            int temp = i;
            while (temp < n && traversal[temp] != '-') {
                temp++;
            }

            int t = stoi(traversal.substr(i, temp - i));
            TreeNode* nn = new TreeNode(t);

            while (count < st.size()) {
                st.pop();
            }

            if (!st.empty()) {
                if (!st.top()->left) st.top()->left = nn;
                else st.top()->right = nn;
            }

            st.push(nn);
            i = temp;
        }

        while (st.size() > 1) {
            st.pop();
        }

        return st.top();
    }
};
