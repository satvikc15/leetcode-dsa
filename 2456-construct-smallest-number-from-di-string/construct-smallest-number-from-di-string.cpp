class Solution {
public:
    string smallestNumber(string pattern) {
        int t=1;
        int n=pattern.size();
        vector<int> temp(n+1,-1);
        for(int i=0;i<=n;i++){
            if(i==n) temp[i]=t++;
            else if(pattern[i]=='I'){
                temp[i]=t++;
            }else{
                int k=i;
                while(k<n && pattern[k]=='D'){
                    k++;
                }
                int g=k;
                while(k>=i){
                    temp[k--]=t++;
                }
                i=g;
            }
        }
        string ans ="";
        for(auto it:temp){
            ans+=it+'0';
        }
        return ans;
    }
};