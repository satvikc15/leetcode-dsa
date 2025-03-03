class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less,great;
        int count=0;
        for(auto it:nums){
            if(it>pivot){
                great.push_back(it);
            }else if(it<pivot){
                less.push_back(it);
            }else{
                count++;
            }
        }
        vector<int> ans(less.begin(),less.end());
        while(count--) ans.push_back(pivot);
        for(auto it:great){
            ans.push_back(it);
        }
        return ans;
    }
};