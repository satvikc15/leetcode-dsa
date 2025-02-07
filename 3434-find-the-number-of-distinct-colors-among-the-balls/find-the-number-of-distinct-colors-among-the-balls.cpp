class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> mpp1,mpp2;
        vector<int> ans;
        for(auto it:queries){
            int ball=it[0];
            int col=it[1];
            if(mpp1.find(ball)!=mpp1.end()){
                mpp2[mpp1[ball]]--;
                if(mpp2[mpp1[ball]]==0){
                    mpp2.erase(mpp1[ball]);
                }
                mpp1[ball]=col;
                mpp2[col]++;
            }else{
                    mpp1[ball]=col;
                    mpp2[col]++;
            }
            ans.push_back(mpp2.size());
        }
        return ans;
    }
};