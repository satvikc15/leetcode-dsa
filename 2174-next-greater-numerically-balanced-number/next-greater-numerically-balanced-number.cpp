class Solution {
public:
    int nextBeautifulNumber(int n) {
        vector<int> count(10,0);
        vector<int> arr;
        generate(0,count,arr);
        sort(arr.begin(),arr.end());
        for(auto it:arr){
            if(it>n) return it;
        }
        return -1;
    }
    void generate(int num,vector<int>&count,vector<int>&arr){
        if(num!=0 && fun(num,count)){
            arr.push_back(num);
        }
        if(num>1224444) return;
        for(int i=1;i<=7;i++){
            if(count[i]<i){
                count[i]++;
                generate(num*10+i,count,arr);
                count[i]--;
            }
            
        }
    }
    bool fun(int num,vector<int>&count){
        for(int i=1;i<=7;i++){
            if(count[i]!=i && count[i]!=0) return false;
        }
        return true;
    }
};