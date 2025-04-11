class Solution {
public:
    bool pos(int i) {
        int temp = i;
        int size = 0, sumf = 0, sumb = 0;
        while (temp) {
            temp = temp / 10;
            size++;
        }
        if (size % 2 != 0) return false;
        int mid = size / 2;
        size = 0;
        while (i) {
            int t = i % 10;
            i = i / 10;
            size++;
            if (size <= mid) {
                sumb += t;
            } else {
                sumf += t;
            }
        }
        return sumb == sumf;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            if (pos(i)) {
                count++;
            }
        }
        return count;
    }
};
