class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> temp;
        for(int i=0; i<weights.size()-1; i++) {
            temp.push_back(weights[i] + weights[i+1]);
        }
        sort(temp.begin(), temp.end());
        long long mini = 0, maxi = 0;
        int n = temp.size();
        for(int i=0; i<k-1; i++) {
            mini += temp[i];
            maxi += temp[n-1-i];
        }
        return maxi - mini;
    }
};
