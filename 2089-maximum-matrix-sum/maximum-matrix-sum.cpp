class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0LL;
        int mini = INT_MAX;
        int neg=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0){
                    neg++;
                }
                mini = min(mini,abs(matrix[i][j]));
            }
        }
        cout << mini <<  endl;
        return neg%2==0 ? sum : sum - 2*mini;
    }
};