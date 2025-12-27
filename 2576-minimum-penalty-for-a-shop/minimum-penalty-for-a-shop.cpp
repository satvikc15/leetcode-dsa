class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int pen = n;          
        int cy = 0;           
        int cn = 0;          
        int ans = 0;

        for (auto it : customers) {
            if (it == 'Y') cy++;
            else cn++;
        }

        int totalN = cn;
        int count = 0;

        if (cy < pen) {
            pen = cy;
            ans = 0;
        }

        for (auto it : customers) {
            if (it == 'Y') cy--;
            else cn--;

            count++;  

            int curPen = (totalN - cn) + cy;

            if (curPen < pen) {
                pen = curPen;
                ans = count;
            }
        }

        return ans;
    }
};
