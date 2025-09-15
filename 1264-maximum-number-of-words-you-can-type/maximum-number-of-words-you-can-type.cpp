class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,int> mpp;
        for(auto it:brokenLetters){
            mpp[it]++;
        }
        int i=0;
        int count=0;
        bool flag;
        while(i<text.size()){
            flag=false;
            while(i<text.size() && text[i]!=' '){
                cout << text[i] << "";
                if(mpp.find(text[i])!=mpp.end()){
                                flag=true;
                }
                i++;
            }
            i++;
            cout << endl;
            if(!flag) count++;
        }
         //if(flag) count++;
        return count;
    }
};