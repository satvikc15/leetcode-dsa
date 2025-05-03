class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int> res(n,0);
        int force=0;
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R'){
                force=n;
            }else if(dominoes[i]=='L'){
                force=0;
            }
            else{
                force=max(0,force-1);
            }
            res[i]+=force;
        }
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='R'){
                force=0;
            }else if(dominoes[i]=='L'){
                force=n;
            }
            else{
                force=max(0,force-1);
            }
            res[i]-=force;
        }
        string ans="";
        for(auto it:res){
            if(it>0){
                ans+="R";
            }else if(it<0){
                ans+="L";
            }
            else{
                ans+=".";
            }
        }
        return ans;
    }
};