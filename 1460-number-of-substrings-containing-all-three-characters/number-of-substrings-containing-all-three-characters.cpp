class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> mpp;
        int l=0;
        int r=0;
        int count=0;
        while(r<s.size()){
            mpp[s[r]]++;
            while(mpp.size()==3){
                count+=(s.size()-r);
                mpp[s[l]]--;
                if(mpp[s[l]]==0) mpp.erase(s[l]);
                l++;
            }
            r++;
        }
        return count;
    }
};