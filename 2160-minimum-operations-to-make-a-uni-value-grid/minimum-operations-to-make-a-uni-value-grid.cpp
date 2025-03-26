class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> temp;
        long long sum=0LL;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]%x!=grid[0][0]%x){
                    return -1;
                }
                temp.push_back(grid[i][j]);
                sum+=grid[i][j];
            }
        }
        int pre=0;
        int ans=INT_MAX;
        int n=temp.size();
        sort(temp.begin(), temp.end());
        for(int i=0;i<n;i++){
            int t=((i*temp[i]-pre)+(sum-pre-(temp[i]*(n-i))))/x;
            pre+=temp[i];
            ans=min(ans,t);
        }
        return ans;
    }
};