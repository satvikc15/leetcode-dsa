class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        const int n = tops.size();
        if (n == 0) return 0;

        int a = 0, b = 0, c = 0, d = 0;
        bool ok1 = true, ok2 = true, ok3 = true, ok4 = true;

        vector<int> t1 = tops, b1 = bottoms;
        vector<int> t2 = tops, b2 = bottoms;
        vector<int> t3 = tops, b3 = bottoms;
        vector<int> t4 = tops, b4 = bottoms;

        int X = tops[0];
        int Y = bottoms[0];

        for (int i = 0; i < n; i++) {
            if (t1[i] == X) continue;
            if (b1[i] == X) {
                a++;
                swap(t1[i], b1[i]);
            } else {
                ok1 = false;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (b2[i] == X) continue;
            if (t2[i] == X) {
                b++;
                swap(t2[i], b2[i]);
            } else {
                ok2 = false;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (t3[i] == Y) continue;
            if (b3[i] == Y) {
                c++;
                swap(t3[i], b3[i]);
            } else {
                ok3 = false;
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (b4[i] == Y) continue;
            if (t4[i] == Y) {
                d++;
                swap(t4[i], b4[i]);
            } else {
                ok4 = false;
                break;
            }
        }

        int ans = INT_MAX;
        if (ok1) ans = min(ans, a);
        if (ok2) ans = min(ans, b);
        if (ok3) ans = min(ans, c);
        if (ok4) ans = min(ans, d);
        return (ans == INT_MAX ? -1 : ans);
    }
};
