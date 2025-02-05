class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int a=0,b=0;
        int n=s1.size();
        if(s1==s2) return true;
        while(a<n && b<n){
            if(s1[a]==s2[b]){
                a++;
                b++;
            }
            else{
                int temp=a;
                while(temp<n){
                    if(s1[temp]==s2[b]){
                        swap(s1[temp],s1[a]);
                        if(s1==s2) return true;
                        else swap(s1[temp],s1[a]);
                        
                    }
                    temp++;
                }
                if(temp==n) return false;
            }
        }
        return true;
    }
};