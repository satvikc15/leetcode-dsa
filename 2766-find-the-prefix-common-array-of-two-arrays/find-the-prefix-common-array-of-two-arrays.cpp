class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_set<int> st;
        vector<int> ans(A.size());
        for(int i=0;i<A.size();i++){
            st.insert(A[i]);
            st.insert(B[i]);
            ans[i]=(2*(i+1)-st.size());
        }
        return ans;
    }
};