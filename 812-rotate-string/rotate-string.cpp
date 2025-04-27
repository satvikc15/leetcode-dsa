class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        s+=s;
        for(int i=0;i<=s.size()-goal.size();i++){
            if(s[i]==goal[0]){
                int n=goal.size();
                int temp=i;
                int l=0;
                while( l<n && s[temp]==goal[l]){
                    l++;
                    temp++;
                }
                if(l==n) return true;
            }
        }
        return false;
    }
};