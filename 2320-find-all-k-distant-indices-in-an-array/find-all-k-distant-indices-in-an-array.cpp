class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<pair<int,int>> temp;
        int n=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==key){
                temp.push_back({max(0,i-k),min(i+k,n)});
            }
        }
        set<int> ans;
        for(auto [a,b]:temp){
            for(int i=a;i<=b;i++){
                ans.insert(i);
            }
        }
        vector<int> fin(ans.begin(),ans.end());
        //sort(fin.begin(),fin.end());
        return fin;
    }
};