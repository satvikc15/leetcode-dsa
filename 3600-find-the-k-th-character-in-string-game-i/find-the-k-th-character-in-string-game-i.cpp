class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        while(word.size()<k){
            int s=word.size();
            for(int i=0;i<s;i++){
                if(word[i]=='z'){
                    word+='a';
                }
                else{
                   char t = word[i]+1;
                   word+=t; 
                }
            }
        }
        return word[k-1];
    }
};