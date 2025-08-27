class Solution {
public:
    string reverseWords(string s) {

        for(int i=0;i<s.size();i++){
            int j=i;
            while(j<s.size() && s[j]!=' '){
                j++;
            }
            int ni=i,nj=j-1;
            while(ni<nj){
                swap(s[ni++],s[nj--]);
            }
            while(j<s.size() && s[j]==' '){
                j++;
            }
            i=j-1;
        }
        reverse(s.begin(),s.end());
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
            while(i<n && s[i]==' '){
                i++;
            }
            if(ans.size()!=0) ans+=' ';
            while(i<n && s[i]!=' '){
                
                ans+=s[i++];
            }
            while(i<n && s[i]==' '){
                i++;
            }
            i--;
        }
        //ans = ans.substr(0,ans.size()-1);
        return ans;
    }
};