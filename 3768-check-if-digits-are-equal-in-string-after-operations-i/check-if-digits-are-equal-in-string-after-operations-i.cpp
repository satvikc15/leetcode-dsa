class Solution {
public:
    bool hasSameDigits(string s) {
        while(true){
            string temp="";
            for(int i=0;i<s.size()-1;i++){
                int a=s[i]-'0';
                int b=s[i+1]-'0';
                int num = (a+b)%10;
                //cout << a << " " << b << endl;
                temp+=to_string(num);
                
            }
            //cout << temp << endl;
                if(temp.size()==2){
                    for(int i=0;i<temp.size()-1;i++){
                        if(temp[i]!=temp[temp.size()-1]){
                            return false;
                        }
                    }
                    return true;
                }
                if(temp.size()<2){
                    return false;
                }
                s=temp;
            
        }
        return false;
    }
};