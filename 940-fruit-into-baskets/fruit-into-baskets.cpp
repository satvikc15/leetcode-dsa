class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxi=0;
        map<int,int> mpp;
        int r=0,l=0,n=fruits.size();
        while(r<n){
            mpp[fruits[r]]++;
            while(l<=r && mpp.size()>2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0) mpp.erase(fruits[l]);
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
     
        return maxi;
    }
};