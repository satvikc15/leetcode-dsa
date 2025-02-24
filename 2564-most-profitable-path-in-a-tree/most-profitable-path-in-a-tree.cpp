class Solution {
public:
    bool dfs(int bob, int prev, int time, map<int, vector<int>>& mpp, unordered_map<int, int>& mp2) {
        if (bob == 0) {
            mp2[bob] = time;
            return true;
        }
        for (int it : mpp[bob]) {
            if (it == prev) continue;
            if (dfs(it, bob, time + 1, mpp, mp2)) {
                mp2[bob] = time;
                return true;
            }
        }
        return false;
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        map<int, vector<int>> mpp;
        for (auto& it : edges) {
            mpp[it[0]].push_back(it[1]);
            mpp[it[1]].push_back(it[0]);
        }

        unordered_map<int, int> mp2;
        dfs(bob, -1, 0, mpp, mp2);

        queue<vector<int>> q;
        int ans = INT_MIN;
        q.push({0, -1, 0, amount[0]});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int cur = it[0], par = it[1], time = it[2], amt = it[3];

            bool isLeaf = true;
            for (int i : mpp[cur]) {
                if (i == par) continue;

                int temp = amount[i];
                if (mp2.find(i) != mp2.end()) {
                    if (time + 1 < mp2[i]) {
                        temp = amount[i];
                    } else if (time + 1 == mp2[i]) {
                        temp = amount[i] / 2;
                    } else {
                        temp = 0;
                    }
                } else {
                    temp = amount[i];
                }

                q.push({i, cur, time + 1, amt + temp});
                isLeaf = false;
            }
            if (isLeaf) {
                ans = max(ans, amt);
            }
        }
        return ans;
    }
};