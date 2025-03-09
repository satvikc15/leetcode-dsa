class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int l = 0, r = 1, count = 0, n = colors.size();
        vector<int> temp = colors;  
        for (int i = 0; i < n; i++) {
            temp.push_back(colors[i]);  
        }
        while (r < n + k - 1) {
            if (temp[r] != temp[r - 1]) {
                r++;
            } else {
                l = r;
                r++;
            }
            if (r - l == k) { 
                count++; 
                l++; 
            }
        }
        return count;
    }
};
