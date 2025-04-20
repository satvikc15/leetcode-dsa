class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int,int> mpp;
        for(auto it:answers){
            mpp[it]++;
        }
        int ans=0;
        for(auto [a,b]:mpp){
            int numOfGrps = ceil((double)b/(a+1));
            ans+=numOfGrps*(a+1);
        }
        return ans;
    }
};