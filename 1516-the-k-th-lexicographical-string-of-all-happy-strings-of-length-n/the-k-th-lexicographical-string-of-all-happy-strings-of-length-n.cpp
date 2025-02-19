class Solution {
public:
    void fun(string temp, int n, priority_queue<string, vector<string>, greater<string>>& pq) {
        if (temp.size() == n) {
            pq.push(temp);
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (temp.empty() || temp.back() != i + 'a') {
                fun(temp + char(i + 'a'), n, pq);
            }
        }
    }

    string getHappyString(int n, int k) {
        priority_queue<string, vector<string>, greater<string>> pq;
        fun("", n, pq);
        if (k > pq.size()) return "";
        while (--k) pq.pop();
        return pq.top();
    }
};
