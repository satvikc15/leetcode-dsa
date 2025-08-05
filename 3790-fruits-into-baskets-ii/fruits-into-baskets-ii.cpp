class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int s=0;
        for(auto it:fruits){
            bool flag=false;
            for(int i=0;i<baskets.size();i++){
                if(baskets[i]>=it){
                    baskets[i]=0;
                    flag=true;
                    break;
                }
            }
            if(!flag) s++;
        }
        return s;
    }
};