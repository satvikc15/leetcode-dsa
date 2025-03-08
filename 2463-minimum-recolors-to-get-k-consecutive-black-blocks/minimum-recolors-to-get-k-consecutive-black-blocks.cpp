class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        unordered_map<char,int> mpp;
        int l=0;
        int r=0;
        
        for(r=0;r<k;r++) mpp[blocks[r]]++;
        int res=mpp['W'];
        while(r<blocks.size()){
            
            mpp[blocks[l]]--;
            mpp[blocks[r]]++;
            r++;
            l++;
            res=min(mpp['W'],res);
        }
        return res;
    }
};