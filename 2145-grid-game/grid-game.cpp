class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long n = grid[0].size();
        vector<long long> pref1(n);
        pref1[0]=grid[0][0];
        vector<long long> pref2(n);
        pref2[0]=grid[1][0];
        for(long long i=1LL;i<n;i++){
            pref1[i]=grid[0][i]+pref1[i-1];
            pref2[i]=grid[1][i]+pref2[i-1];
        }
        long long res = LLONG_MAX;
        for(long long i=0LL;i<n;i++){
            long long top=pref1[n-1]-pref1[i];
            long long bottom=0;
            if(i>0) bottom=pref2[i-1];
            long long temp = max(top,bottom);
            res = min(res,temp);
        }
        return res;
    }
};