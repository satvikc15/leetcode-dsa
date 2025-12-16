class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> maxi(prices.size(),-1e9);
        maxi[prices.size()-1]=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            maxi[i]=max(maxi[i+1],prices[i]);
        }
        int ans=0;
        for(int i=0;i<prices.size();i++){
            ans=max(ans,abs(maxi[i]-prices[i]));
        }
        return ans;
    }
};