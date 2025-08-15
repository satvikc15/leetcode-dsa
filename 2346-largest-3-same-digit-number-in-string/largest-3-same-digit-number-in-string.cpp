class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        int l=0;
        int r=0;
        map<char,int> mpp;
        int maxi=-1;
        while(r<n){
            mpp[num[r]]++;
            while(l<=r && mpp.size()>1){
                mpp[num[l]]--;
                if(mpp[num[l]]==0) mpp.erase(num[l]);
                l++;
            }
            if(r-l+1==3) maxi=max(maxi,stoi(num.substr(l,r-l+1)));
            r++; 
        }
        if(maxi==0){
            return "000";
        }
        return maxi==-1 ? "":to_string(maxi);
    }
};