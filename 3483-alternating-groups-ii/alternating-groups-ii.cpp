class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int l = 0, r = 1, count = 0, n = colors.size();
        
        while (r < n + k - 1) {
            if (colors[r%n] != colors[(r - 1)%n]) {
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
