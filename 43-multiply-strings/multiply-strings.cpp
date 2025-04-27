class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        vector<int>res(num1.size()+num2.size(),0);
        for(int i=0;i<num1.size();i++){
            for(int j=0;j<num2.size();j++){
                res[i+j]+=(num1[i]-'0')*(num2[j]-'0');
                res[i+j+1]+=res[i+j]/10;
                res[i+j]=res[i+j]%10;
            }
        }
        int beg=res.size()-1;
        while(beg>0 && res[beg]==0){
            beg--;
        }
        string ans="";
        for(int i=beg;i>=0;i--){
            ans+=to_string(res[i]);
        }
        return ans;
    }
};