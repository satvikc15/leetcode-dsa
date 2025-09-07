class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int num=n/2;
        
        for(int i=-num;i<=num;i++){
            if(n%2==0 && i==0) continue;
            ans.push_back(i);
        }
        return ans;
    }
};