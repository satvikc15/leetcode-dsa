#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void fun(string s, int a, int b, unordered_set<string>& vis, vector<string>& arr) {
        if (vis.count(s)) return;
        vis.insert(s);
        arr.push_back(s);

        string added = s;
        for (int i = 1; i < s.size(); i += 2) {
            int num = (added[i] - '0' + a) % 10;
            added[i] = '0' + num;
        }

        fun(added, a, b, vis, arr);

        int n = s.size();
        string rotated = s.substr(n - b) + s.substr(0, n - b);
        fun(rotated, a, b, vis, arr);
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> vis;
        vector<string> arr;

        fun(s, a, b, vis, arr);

        sort(arr.begin(), arr.end());
        return arr[0];
    }
};
