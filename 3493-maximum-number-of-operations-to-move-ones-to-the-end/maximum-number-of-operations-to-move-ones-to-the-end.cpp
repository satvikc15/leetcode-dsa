class Solution {
public:
    int maxOperations(string s) {
        int count=0;
        int ones=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                int temp=i;
                //ones++;
                while(temp<s.size() && s[temp]=='0'){
                    temp++;
                } 
                count+=ones;
                i=temp-1;
            }else{
                ones++;
            }
        }
        return count;
    }
};