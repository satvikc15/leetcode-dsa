class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count = 0;
        stack<int> st;

        for (int x : nums) {

            while (!st.empty() && st.top() > x) st.pop();

            if (x>0 && (st.empty() || st.top() < x)) {
                count++;
                st.push(x);
            }
        }
        return count;
    }
};
