class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        set<int> ans;
        set<int> prev;

        for (int num : arr) {
            set<int> curr;
            curr.insert(num);
            for (int x : prev) {
                curr.insert(x | num);
            }
            prev = curr;
            for (int x : curr) {
                ans.insert(x);
            }
        }

        return ans.size();
    }
};
