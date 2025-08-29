class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256,0);
        for(auto it:t){
            freq[it]++;
        }
        int l=0,r=0,n=s.size();
        int m=t.size();
        int count=0;
        int mini=1e9;
        int si = -1;
        while(r<n){
            if(freq[s[r]]>0) count++;
            freq[s[r]]--;
            while(count==m){
                if(r-l+1<mini){
                    mini=r-l+1;
                    si=l;
                }
                freq[s[l]]++;
                if(freq[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        return si==-1?"":s.substr(si,mini);
    }
};