class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>> mpp;
        int m=mat.size(),n=mat[0].size();
        //cout << m << " " << n<< endl;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mpp[mat[i][j]]={i,j};
            }
        }
        map<int,int> l,s;
        for(int k=0;k<arr.size();k++){
            int it=arr[k];
            int i=mpp[it].first;
            int j=mpp[it].second;
            l[i]++;s[j]++;
            //cout << i << " "<< j << endl;
            if(l[i]==n || s[j]==m) return k;
            
        }
        return -1;
    }
};