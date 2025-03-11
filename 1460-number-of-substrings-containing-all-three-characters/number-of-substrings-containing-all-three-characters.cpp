class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> mpp(s.size(),0);
        int l=0;
        int r=0;
        int count=0;
        while(r<s.size()){
            mpp[s[r]-'a']++;
            while(mpp[0]>0 && mpp[1]>0 && mpp[2]>0){
                count+=(s.size()-r);
                mpp[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return count;
    }
};